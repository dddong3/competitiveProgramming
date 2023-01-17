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
    	int n, m;
	cin >> n;
	while(cin >> n >> m) {
		m--;
		int j = 0, k = n - 2;
		while(k > j) {
			int tmp = m;
			m ^= ((!(tmp >> k & 1) && tmp >> j & 1) || (tmp >> k & 1 && !(tmp >> j & 1))) << k;
			m ^= ((!(tmp >> k & 1) && tmp >> j & 1) || (tmp >> k & 1 && !(tmp >> j & 1))) << j;
			k--, j++;
		}
		n--;
		cout << (1 << n) + m << '\n';
	}
}