#define letmeAC ios_base::sync_with_stdio(0), cin.tie(0)
#define DD(x) cout << #x << " = " << x << '\n'
#define ll long long
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;

struct trie {
    int idx = -1;
    trie *nxt[10] = {};
} *root = new trie;

void insert(string &s, int ii) {
    trie *cur = root;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s.size() - i > 40) break;
        int idx = s[i] - '0';
        if(!cur->nxt[idx]) cur->nxt[idx] = new trie;
        cur = cur->nxt[idx];
        if(cur->idx == -1) cur->idx = ii;
    }
}

char carry(int &cnt) {
    int tmp = cnt % 10;
    cnt /= 10;
    return tmp + '0';
}

void add(string &a, string &b) {
    string c = "";
    int i = 0, j = 0, cnt = 0;
    while(i < a.size() && j < b.size()) {
        cnt += a[i++] + b[j++] - '0' - '0';
        c += carry(cnt);
    }
    while(i < a.size() || j < b.size()) {
        if(i < a.size()) cnt += a[i++] - '0';
        if(j < b.size()) cnt += b[j++] - '0';
        c += carry(cnt);
    }
    while(cnt) c += carry(cnt);
    a = c;
}

int main() {
    letmeAC;
    #ifdef plsAC
        freopen("ipt.in", "r", stdin);
        freopen("opt.out", "w", stdout);
	#endif
    int t = 1, cs;
    string s;
    cin >> cs;

    string a = "1", b = "1";
    for(int i = 0; i < 100000; i++) {
        insert(a, i);
        add(a, b);
        swap(a, b);
    }

    while(cs--) {
        cin >> s;
        trie *cur = root;
        int i = 0;
        while(i < s.size()) {
            int idx = s[i] - '0';
            if(!cur->nxt[idx]) break;
            cur = cur->nxt[idx];
            i++;
        }
        cout << "Case #" << t++ << ": " << (i == s.size()? cur->idx : -1) << '\n';
    }
}