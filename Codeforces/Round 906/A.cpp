#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N];

void solve() {
    i64 n, m, t, ans = 0;
    scanf("%lld", &n); getchar();
    map<i64,i64> mp;
    mp.clear();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", &t);
        mp[t]++;
    }
    if (mp.size() > 2) {printf("No\n"); return;}
    if (mp.size() == 1) {printf("Yes\n"); return;}
    i64 i = 0;
    for (auto& it : mp) {
        a[i++] = it.second;
    }
    if (abs(a[0] - a[1]) > 1) {printf("No\n"); return;}
	
	printf("Yes\n");
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
