#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
   // Complete this function
    char camma;
    stringstream ss(str);
    int x;
    vector<int> result;
    while (ss >> x) {
        result.push_back(x);
        ss >> camma;
    }
    return(result);
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
