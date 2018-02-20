#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

struct Tag {
	public:
		std::string name;
		std::map<std::string, std::string> attval;
		std::vector<Tag*> childtags; // I didn't write destructor (It has to be written for practical usages).
};

std::vector<std::string> Words(std::string text) {
    std::vector<std::string> words;
    std::string signWord;
    std::string lastWord;
    for (size_t i = 0; i < text.length(); i++) {
        if ((text[i] == '<') | (text[i] == '>') | (text[i] == '/') | (text[i] == '\\') | (text[i] == '=') | (text[i] == '\"') | (text[i] == '~') | (text[i] == ' ') ) {
			signWord = text[i];
		}
		else {
			lastWord.append(1, text[i]);
			signWord.clear();
		}
        if ((lastWord != "") & (signWord != "")) {
            words.push_back(lastWord);
            lastWord.clear();
        }
        if ((signWord != "") & (signWord != " ")) {
            words.push_back(signWord);
            signWord.clear();
        }
    }
    if (lastWord != "")
	{
		words.push_back(lastWord);
		lastWord.clear();
	}
    return(words);
}

std::vector<std::string> Query(std::string text) {
    std::vector<std::string> query_words;
    std::string word;
    for (size_t i = 0; i < text.length(); i++) {
        if ((text[i] == '.') | (text[i] == '~')){
			query_words.push_back(word);
			word = text[i];
			query_words.push_back(word);
			word = "";
			continue;
		}
		word.append(1, text[i]);
    }
    if (word != "") {
		query_words.push_back(word);
    }
    return(query_words);
}

bool accepted_name(std::string name) {
	if ((name == "<") | (name == "\"") | (name == "=") | (name == ">") | (name == "/"))
		return false;
	return true;
}

Tag* extract_tags(std::vector<std::string> words)
{
	std::string expected_state = "opening tag name", open_signs = "", current_attribute_name;
	Tag *parent_of_tags, *current_tag, *child_tag, *parent_tag;
	current_tag = new Tag();
	parent_of_tags = current_tag;
	parent_of_tags->name = "ParentOfTags";
	for (size_t i = 0; i < words.size(); i++) {
		if (accepted_name(words[i])) {
			// opening tag name
			if (expected_state == "opening tag name") {
				expected_state = "attribute name";
				child_tag = new Tag();
				child_tag->name = words[i];
				current_tag->childtags.push_back(child_tag);
				parent_tag = current_tag;
				current_tag = child_tag;
				continue;
			}
			// attribute name
			if (expected_state == "attribute name") {
				expected_state = "attribute value";
				current_attribute_name = words[i];
				current_tag->attval[current_attribute_name] = "";
				continue;
			}
			// closing tag name
			if (expected_state == "closing tag name") {
				if (words[i] == current_tag->name) {
					expected_state = "no state";
					current_tag = parent_tag;
					continue;
				} else {
					std::cout << "Error for closing tag!" << std::endl;
					break;
				}
			}
			// attribute value
			if (expected_state == "attribute value") {
				expected_state = "attribute name";
				current_tag->attval[current_attribute_name] = words[i];
				continue;
			}
		} else {
			// <
			if (words[i] == "<") {
				if ((open_signs.back() == '>') | (open_signs.empty())) {
					open_signs.append("<");
					expected_state = "opening tag name";
				} else {
					std::cout << "Error while parsing < !" << std::endl;
					break;
				}
			}
			// =
			if (words[i] == "=") {
				if (open_signs.back() == '<') {
					open_signs.append("=");
					expected_state = "no state";
				} else {
					std::cout << "Error while parsing = !" << std::endl;
					break;
				}
			}
			// "
			if (words[i] == "\"") {
				if (open_signs.back() == '\"') {
					expected_state = "attribute name";
					open_signs.pop_back();
					open_signs.pop_back();
				} else if (open_signs.back() == '=') {
					expected_state = "attribute value";
					open_signs.append("\"");
				} else {
					std::cout << "Error while parsing \" !" << std::endl;
					break;
				}
			}
			// >
			if (words[i] == ">") {
				if (open_signs.back() == '<') {
					open_signs.pop_back();
					expected_state = "no state";
				} else {
					std::cout << "Error while parsing > !" << std::endl;
					break;
				}
			}
			// /
			if (words[i] == "/") {
				if (open_signs.back() == '<') {
					expected_state = "closing tag name";
				} else {
					std::cout << "Error while parsig / !" << std::endl;
					break;
				}
			}
		}
	}
	if (!open_signs.empty()) {
		std::cout << "Error in number of signs!" << std::endl;
	}
	return parent_of_tags;
}

std::string find_value(Tag *tags, std::vector<std::string> tag_seq)
{
	std::string state = "tag", ret_value = "Not Found!";
	Tag *current_tag = tags;
	for (size_t i = 0; i < tag_seq.size(); i++)
	{
		if (tag_seq[i] == ".")
		{
			continue;
		}
		if (tag_seq[i] == "~")
		{
			state = "attribute";
			continue;
		}
		if (state == "tag")
		{
			for (size_t j = 0; j < current_tag->childtags.size(); j++)
			{
				if (current_tag->childtags[j]->name == tag_seq[i])
				{
					current_tag = current_tag->childtags[j];
					break;
				}
			}
			continue;
		}
		if (state == "attribute")
		{
			if (current_tag->attval.find(tag_seq[i]) != current_tag->attval.end())
			{
				ret_value = current_tag->attval[tag_seq[i]];
			}
			else
			{
				ret_value = "Not Found!";
			}
			break;
		}
	}
	return (ret_value);
}

int main() {
	//std::vector<std::string> tag_words = Words("<tag1 att1=\"val1\" att4=\"val4\"><tag2 att2=\"val2\" att5=\"val5\"></tag2><tag3 att3=\"val3\"></tag3></tag1>");
	//std::vector<std::string> query_words = Words("tag1~att3");
	//for (size_t i = 0; i < query_words.size(); i++)
	//	std::cout <<  query_words[i] << std::endl;
	//Tag* tags = extract_tags(tag_words);
	// std::cout << ((tags->childtags[0])->childtags[0])->name << std::endl;
	// std::cout << tags->childtags[0]->childtags[0]->attval["att5"] << std::endl;
	//std::cout << find_value(tags, query_words) << std::endl;
    //return 0;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    size_t n, q;
    std::string input_text, temp_text;
    std::vector<std::string> input_query;
    std::cin >> n >> q;
    std::cin.ignore();
    for (size_t i = 0; i < n; i++)
    {
        std::getline(std::cin, temp_text);
        input_text += temp_text;
        temp_text = "";
    }
    temp_text = "";
    for (size_t i = 0; i < q; i++)
    {
        std::getline(std::cin, temp_text);
        input_query.push_back(temp_text);
        temp_text = "";
    }
    std::vector<std::string> tag_words = Words(input_text);
	//for (size_t i = 0; i < tag_words.size(); i++)
		//std::cout <<  tag_words[i] << std::endl;
	//for (size_t i = 0; i < query_words.size(); i++)
		//std::cout <<  query_words[i] << std::endl;
	Tag* tags = extract_tags(tag_words);
	for (size_t i = 0; i < input_query.size(); i++)
	{
		//for (size_t j = 0; j < Query(input_query[i]).size(); j++)
		//{
			//std::cout << Query(input_query[i])[j] << std::endl;
		//}
		std::cout << find_value(tags, Query(input_query[i])) << std::endl;
	}
    return 0;
}
