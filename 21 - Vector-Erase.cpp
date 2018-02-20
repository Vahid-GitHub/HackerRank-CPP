#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, n, x, a, b;
    string line;
    vector<long long> v;
    cin >> N >> ws;
    getline(cin, line);
    istringstream sline(line);
    while (sline >> n)
        v.push_back(n);
    cin >> x;
    v.erase(v.begin() + x - 1);
    cin >> a >> b;
    v.erase(v.begin() + a - 1, v.begin() + b - 1);
    cout << v.size() << endl;
    for (auto &value: v)
        cout << value << " ";
    cout << endl;
    return 0;
}
