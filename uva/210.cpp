#define BUG(x) assert(x)
#define letmeAC ios_base::sync_with_stdio(0), cin.tie(0)
#define DD(x) cout << #x << " = " << x << '\n'
#define ll long long
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;

int main() {
	letmeAC;
	#ifdef plsAC
		freopen("ipt.in", "r", stdin);
		freopen("opt.out", "w", stdout);
	#endif
	string s, t;
	int cs, n, lim, x;
	pair<string, int> tmp;
	cin >> cs;
	while (cs--) {
		cin >> n;
		map<string, int> mp, var;
		cin >> mp["var"] >> mp["print"] >> mp["lock"] >> mp["unlock"] >> mp["end"] >> lim;
		for (int i = 0; i < 26; i++) var[string(1, 'a' + i)] = 0;
		deque<int> pros, wait;
		deque<pair<string, int>> cmd[n + 1];
		for (int i = 1; i <= n; i++) {
			pros.push_back(i);
			while (cin >> s) {
				if (s == "end") break;
				if (s.size() == 1) cin >> t >> x, tmp = { s, x };
				else if (s == "print") cin >> t, tmp = { s, t[0] - 'a' };
				else tmp.ff = s;
				cmd[i].push_back(tmp);
			}
		}
		bool isLock = false;
		while (!pros.empty()) {
			int id = pros.front(), curTime = 0, waitUnlock = false;
			pros.pop_front();
			while (!cmd[id].empty() && curTime < lim) {
				auto tp = cmd[id].front();
				cmd[id].pop_front();
				if (tp.ff.size() == 1) var[tp.ff] = tp.ss, curTime += mp["var"];
				if (tp.ff == "print") cout << id << ": " << var[string(1, 'a' + tp.ss)] << '\n', curTime += mp[tp.ff];
				if (tp.ff == "lock") {
					if (isLock) wait.push_back(id), waitUnlock = true, curTime = lim, cmd[id].push_front(tp);
					else isLock = true, curTime += mp[tp.ff];
				}
				if (tp.ff == "unlock") {
					isLock = false, curTime += mp[tp.ff];
					if (!wait.empty()) pros.push_front(wait.front()), wait.pop_front();
				}
			}
			if (!cmd[id].empty() && !waitUnlock) pros.push_back(id);
		}
		if(cs) cout << '\n';
	}
}