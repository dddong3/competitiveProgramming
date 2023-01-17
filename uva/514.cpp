#pragma GCC optimize("O3,unroll-loops")
#define BUG(x) assert(x)
#define letmeAC ios_base::sync_with_stdio(0), cin.tie(0)
#define DD(x) cout << #x << " = " << x << '\n'
#define ll long long
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;
int n, nums[1005];
int main() {
	#ifdef plsAC
		freopen("ipt.in", "r", stdin);
		freopen("opt.out", "w", stdout);
	#endif
	letmeAC;
	string opt[] = {"No\n", "Yes\n"};
	while(cin >> n && n) {
		while(cin >> nums[0], nums[0]) {
			stack<int> st;
			for(int i = 1; i < n; i++) cin >> nums[i];
			for(int i = 1, j = 0; i <= n; i++) {
				while(i < n && i != nums[j]) st.push(i), i++; 
				st.push(i);
				while(!st.empty() && st.top() == nums[j]) st.pop(), j++;
			}
			cout << opt[st.empty()];
		} 
		cout << '\n';
	}
}