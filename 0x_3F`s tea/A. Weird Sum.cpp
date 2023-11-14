// https://codeforces.com/problemset/problem/1648/A
#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
map<i64, vector<i64>> mp_x, mp_y;

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
    scanf("%lld%lld", &m, &n); getchar();
	for (i64 i = 0; i < m; i++) {
        for (i64 j = 0; j < n; j++) {
            scanf("%lld", &t);
            if (mp_x.find(t) == mp_x.end()) mp_x.insert({t, {j}});
            else mp_x[t].push_back(j);

            if (mp_y.find(t) == mp_y.end()) mp_y.insert({t, {i}});
            else mp_y[t].push_back(i);
        }
	}
    for (auto& it : mp_x) {
        t = 0;
        sort(it.second.begin(), it.second.end());
        for (i64 i = 1; i < it.second.size(); i++) {
            t += (it.second[i] - it.second[i - 1]) * i;
            ans += t;
        }
    }
    for (auto& it : mp_y) {
        t = 0;
        for (i64 i = 1; i < it.second.size(); i++) {
            t += (it.second[i] - it.second[i - 1]) * i;
            ans += t;
        }
    }
	
	printf("%lld\n", ans);
}

int main() {
	i64 _ = 1;
	//scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
