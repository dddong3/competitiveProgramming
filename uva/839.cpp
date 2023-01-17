#define letmeAC ios_base::sync_with_stdio(0), cin.tie(0)
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;

int dd() {
    int l, r, ll, rr, t;
    cin >> l >> ll >> r >> rr;
    if(!l) {
        t = dd();
        if(t == -1) l = -1;
        else l += t; 
    }
    if(!r) {
        t = dd();
        if(t == -1) r = -1;
        else r += t; 
    }
    if(l * ll != r * rr) return -1;
    return l + r;
}

int main() {
    #ifdef plsAC
        freopen("ipt.in", "r", stdin);
        freopen("opt.out", "w", stdout);
	#endif
    letmeAC;
    int t;
    cin >> t;
    while(t--) {
        cout << (dd() > 0? "YES" : "NO") << '\n';
        if(t) cout << '\n';
    }
}