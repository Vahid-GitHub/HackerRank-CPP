#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		/* Enter your code here */   
	        cout << left << hex << showbase << nouppercase;
        	cout << (long long) A << endl;
	        cout << right << setfill('_') << setw(15) << showpos << setprecision(2) << fixed;
	        cout << B << endl;
	        cout << uppercase << setprecision(9) << scientific << noshowpos;
	        cout << C << endl;
	return (0);
}