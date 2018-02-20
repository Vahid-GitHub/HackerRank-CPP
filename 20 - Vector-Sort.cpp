#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, n;
    string line;
    vector<long long> v;
    cin >> N >> ws;
    getline(cin, line);
    istringstream sline(line);
    while (sline >> n)
        v.push_back(n);
    sort(v.begin(), v.end());
    for (auto &value: v)
        cout << value;
    cout << endl;
    return 0;
}
