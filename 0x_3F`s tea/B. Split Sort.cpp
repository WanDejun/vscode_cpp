#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 1e5 + 5;
const i64 MOD = 998244353;
i64 a[N];

void solve() {
    i64 n, m, t, ans = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", &t);
        a[t] = i;
	}
    t = a[1];
    for (i64 i = 2; i <= n; i++) {
        if (a[i] < t) {
            ans++;
        }
        t = a[i];
    }
	
	printf("%lld\n", ans);
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
