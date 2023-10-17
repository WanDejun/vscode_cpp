#include <bits/stdc++.h>

#define pii array<i64, 2>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define FI first
#define SE second
#define i64 long long

using namespace std;

const i64 N = 1e5 + 5;
const i64 MOD = 998244353;
i64  a[N];

void solve() {
    i64 n, p, ans = 0;
    scanf("%lld%lld", &n, &p); getchar();
    for (i64 i = 0; i < n; i++) {
        scanf("%lld", a + i);
    }
    sort(a, a + n);
    for (i64 i = 0; i < n; i++) {
        i64 loc = upper_bound(a, a + n, a[i] * p) - a;
        ans = max(ans, loc - i);
    }
    cout << ans << endl;
}
signed main() {
    solve();

    system("pause");
    return 0;
}
