#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int A[1000], N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = N - 1; i > -1; i--) {
        cout << A[i] << " ";
    }
    return 0;
}
