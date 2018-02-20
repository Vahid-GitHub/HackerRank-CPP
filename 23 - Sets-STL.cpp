#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    set<int> S;
    int q, a, b;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        switch (a) {
        case 1:
            S.insert(b);
            break;
        case 2:
            S.erase(b);
            break;
        case 3:
            cout << ((S.find(b) == S.end())?"No":"Yes") << endl;
            break;
        }
    }
    return 0;
}
