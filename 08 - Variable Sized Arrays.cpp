#include <typeinfo>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void print_vector(vector<int> a) {
	for (size_t i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void print_vector(vector< vector<int> > a) {
	for (auto r: a) {
		for (auto v: r)
			cout << v << " ";
		cout << endl;
	}
}

int main()
{
	int number, n, q;
	vector< vector <int> > a, Q;
	string line;
	// Read n and q
	cin >> n >> q >> ws;
	// cin.ignore();
	// Read values of vectors
	for (int i = 0; i < n; i++) {
		// cout << "i = " << i << endl;
		a.push_back( vector<int>() );
		getline(cin ,line);
		istringstream iss(line);
		while (iss >> number) {
			// cout << typeid(number).name() << endl;
			a[i].push_back(number);
		}
	}
	// Read queries
	for (int i = 0; i < q; i++) {
		Q.push_back( vector<int>());
		getline(cin, line);
		istringstream iss(line);
		while (iss >> number) {
			Q[i].push_back(number);
		}
	}
	// Print queries
	for (int i = 0; i < q; i++) {
		cout << a[Q[i][0]][Q[i][1] + 1] << endl;
	}
    return 0;
}
