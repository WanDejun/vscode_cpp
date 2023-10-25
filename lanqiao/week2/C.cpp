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
    i64 n, k, t, ans = 0, pre, nxt;
    scanf("%lld%lld", &n, &k); getchar();
    scanf("%lld", &pre);
    for (i64 i = 1; i < n; i++) {  
        scanf("%lld", &nxt);
        a[i] = nxt - pre;
        ans += a[i];
        pre = nxt;
    }
    sort(a + 1, a + n, greater<i64>());
    for (i64 i = 0; i < k; i++) {
        ans -= a[i];
    }
    printf("%lld", ans);
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
