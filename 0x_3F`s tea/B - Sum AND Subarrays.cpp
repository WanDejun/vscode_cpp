//https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_b
#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define FI first
#define SE second
#define i64 long long

using namespace std;

const i64 N = 1e3 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N*N/2];

void solve() {
    i64 n, ans = 1ll << 50, k;
    scanf("%lld%lld", &n, &k); getchar();
    for (i64 i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        a[i] += a[i - 1];
    }
    i64 m = 0;
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = i; j <= n; j++) {
            b[m++] = a[j] - a[i - 1];
        }
    }
    sort(b, b + m, [](i64 x, i64 y){return x > y;});
    for (i64 i = 0; i < m; i++) {
        b[i] |= (1ll << 50);
    }
    i64 cnt;
    for (i64 i = 40; i >= 0; i--) {
        cnt = 0;
        for (i64 j = 0; j < m && cnt < k; j++) {
            if ((b[j] & ans) == ans && (b[j] & (1ll << i))) cnt++;
        }
        if (cnt == k) ans += (1ll << i);
    }
    printf("%lld", ans ^= (1ll << 50));
}
signed main() {
    solve();

    system("pause");
    return 0;
}
