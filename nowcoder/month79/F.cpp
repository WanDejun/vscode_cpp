#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long

using namespace std;
const i64 N = 1e5 + 5;
const i64 MOD = 1e3;
map<i64,vector<i64>> mp;

void solve() {
    i64 n, m, ans = 0, t;
    i64 flag = -1;
    scanf("%lld", &n); getchar();
    mp.clear();
    for (i64 i = 0; i < n; i++) {
        scanf("%lld", &t); t %= MOD;
        if (mp.find(t) != mp.end()) mp[t].push_back(i);
        else mp.insert({t, {i}});
        (ans += t) %= MOD;
    }
    if (mp.find(0) != mp.end()) {
        flag = 0;
    }
    else if (mp.find(500) != mp.end() && mp[500].size() > 1) flag = 500;
    else for (i64 i = 1; i < MOD / 2; i++) {
        if (mp.find(i) != mp.end() && mp.find(MOD - i) != mp.end()) {
            flag = i;
            break;
        }
    }
    cout << (flag == -1 ? -1 : ans) << endl;
    switch (flag) {
    case 0:
        cout << 1 << " " << mp[0][0] + 1 << endl;
        break;
    case -1:
        break;
    case 500:
        cout << 2 << " " << mp[500][0] + 1 << " " << mp[500][1] + 1 << endl;
        break;
    default:
        cout << 2 << " " << mp[flag][0] + 1 << " " << mp[MOD - flag][0] + 1 << endl;
        break;
    }
} 

int main() {
	i64 _ = 1;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
