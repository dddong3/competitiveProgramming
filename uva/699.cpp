#pragma GCC optimize("O3,unroll-loops")
#define BUG(x) assert(x)
#define letmeAC ios_base::sync_with_stdio(0), cin.tie(0)
#define DD(x) cout << #x << " = " << x << '\n'
#define ll long long
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;

int arr[1000] = {}, l = 1000, r = -1, cs = 1, x;
int rec(int idx) {
	cin >> x;
	if(x == -1) return 1;
	arr[idx] += x;
	l = min(l, idx), r = max(r, idx);
	return rec(idx - 1) + rec(idx + 1);
}
int main() {
	#ifdef plsAC
		freopen("ipt.in", "r", stdin);
		freopen("opt.out", "w", stdout);
	#endif
	letmeAC;
	while(rec(500) > 1) {
		cout << "Case " << cs++ << ":\n";
		while(l <= r) cout << arr[l] << " \n"[l == r], l++;
		cout << "\n";
		memset(arr, 0, sizeof(arr));
		l = 1000, r = -1;
	}
}