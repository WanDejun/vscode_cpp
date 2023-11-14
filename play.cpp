#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 3e1 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N], n, T, kk, cnt = 0;
map<i64, i64> mp;

void output() {
    auto it = mp.find(T);
    kk = 0;
    while (it->first != it->second) {
        b[kk++] = it->second;
        it = mp.find(it->first - it->second);
    }
    b[kk++] = it->second;
    for (i64 i = kk - 1; i >= 0; i--) {
        printf("%lld ", b[i]);
    }
    putchar('\n');
}

void solve() {
    i64 m = 0, t = 0, ans = 0, cnt = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
    scanf("%lld", &T);
    for (i64 i = 0; i < n; i++) {
        mp.insert({a[i], a[i]});
        if (a[i] == T) { printf("%lld\n", T); }
        for (auto &it : mp) if (it.second != a[i]) {
            mp.insert({it.first + a[i], a[i]});
            if (it.first + a[i] == T) {
                output();
            }
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
/*
5
-7 -3 -2 5 9
0
 */
