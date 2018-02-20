#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, n, q;
    string line;
    vector<long long> v;
    vector<long long>::iterator lb;
    cin >> N >> ws;
    getline(cin, line);
    istringstream sline(line);
    while (sline >> n)
        v.push_back(n);
    sort(v.begin(), v.end());
    cin >> q;
    while (q--) {
        cin >> n;
        lb = lower_bound(v.begin(), v.end(), n);
        if (n == *lb)
            cout << "Yes ";
        else
            cout << "No ";
        cout << lb - v.begin() + 1<< endl;
    }
}
