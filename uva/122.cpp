#pragma GCC optimize("O3,unroll-loops")
#define BUG(x) assert(x)
#define letmeAC ios_base::sync_with_stdio(0), cin.tie(0)
#define DD(x) cout << #x << " = " << x << '\n'
#define ll long long
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;

ll n, md = 1e9 + 7;
map<int,int> mp;
void inst(string s) {
	ll idx = 1, dot = s.find(',');
	for(int i = dot + 1; i < s.size() - 1; i++) idx = (idx * 2 + (s[i] == 'R')) % md;
	mp[idx % md] = stoi(s.substr(1, dot - 1));
	n++;
}

int main() {
	#ifdef plsAC
		freopen("ipt.in", "r", stdin);
		freopen("opt.out", "w", stdout);
	#endif
	letmeAC;
	string s;
	while(cin >> s) {
		mp.clear(); n = 0;
		inst(s);
		while(cin >> s && s != "()") inst(s);
		int cnt = 0;
		stack<ll> st;
		if(mp[1]) st.push(1);
		while(!st.empty()) {
			ll tp = st.top();
			st.pop(); cnt++;
			if(mp[tp * 2 % md]) st.push(tp * 2 % md);
			if(mp[(tp * 2 + 1) % md]) st.push((tp * 2 + 1) % md);
		}
		vector<int> ans;
		for(auto i : mp) if(i.second) ans.emplace_back(i.second);
		if(cnt == n) for(int i = 0; i < ans.size(); i++)
			cout << ans[i] << " \n"[i == ans.size() - 1];
		else cout << "not complete\n";
	}
}