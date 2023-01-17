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
	int n, cr, cc;
	char c;
	map<char, pair<int,int>> matrix;
	cin >> n;
	while(n--) {
		cin >> c >> cr >> cc;
		matrix[c] = {cr, cc};
	}

	string s;
	while(cin >> s) {
		stack<pair<int,int>> st;
		int ans = 0, valid = 1;
		for(int i = 0; i < s.size(); i++)  {
			if(isalpha(s[i])) st.push(matrix[s[i]]);
			if(s[i] == ')') {
				auto tp = st.top();	st.pop();
				auto tp2 = st.top(); st.pop();
				if(tp2.ss != tp.ff) valid = 0;
				ans += tp2.ff * tp.ff * tp.ss;
				st.push({tp2.ff, tp.ss});
			}
		}
		if(valid) cout << ans << '\n';
		else cout << "error\n";
	}
}