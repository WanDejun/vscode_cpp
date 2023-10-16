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
i64 a[N];

void solve() {
    i64 n, ans = 0;
    scanf("%lld", &n); getchar();
    for (i64 i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        a[i] += a[i - 1];
    }
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = i + 1; j <= n; j++) {
            for (i64 k = j + 1; k <= n; k++) {
                ans = max(ans, a[i] & a[j] & a[k]);
            }
        }
    }
    cout << ans;
}
signed main() {
    solve();

    system("pause");
    return 0;
}
