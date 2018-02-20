#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map<string, long> scores;
	int q, a, b;
	string query, name;
	cin >> q >> ws;
	while (q--) {
		getline(cin, query);
		stringstream line(query);
		line >> a;
		switch (a) {
		case 1:
			line >> name;
			line >> b;
			scores[name] += b;
			break;
		case 2:
			line >> name;
			scores.erase(name);
			break;
		case 3:
			line >> name;
			if (scores.find(name) == scores.end())
				cout << 0 << endl;
			else
				cout <<  scores[name] << endl;
		}
	}
    return 0;
}
