#include <iostream>
#include <vector>
using namespace std;

#define FUNCTION(f,op) void f(int &m, int n) {m = (m op n)?m:n;}
#define INF 1000000000
#define io(v) cin>>v
#define toStr(a) #a
#define foreach(v, c) for(size_t c=0;c<v.size();++c)

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}
