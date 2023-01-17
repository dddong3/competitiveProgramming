#pragma GCC optimize("O3,unroll-loops")
#define BUG(x) assert(x)
#define letmeAC ios_base::sync_with_stdio(0), cin.tie(0)
#define DD(x) cout << #x << " = " << x << '\n'
#define ll long long
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifdef plsAC
		freopen("ipt.in", "r", stdin);
		freopen("opt.out", "w", stdout);
	#endif
	letmeAC;
	char c;
	list<char> lst;
	auto it = lst.begin();
	while(cin.get(c)) {
		if(c == '\n') {
			it = lst.begin();
			while(it != lst.end()) cout << *it, it++;
			cout << c;
			lst.clear();
			it = lst.begin();
			continue;
		}
		if(c == '[') it = lst.begin();
		else if(c == ']') it = lst.end();
		else it = lst.insert(it, c), it++;
		
	}
}