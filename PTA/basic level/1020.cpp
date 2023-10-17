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

const i64 N = 1e3 + 5;
const i64 MOD = 998244353;
pair<double, i64> a[N];

void solve() {
    i64 n, d;
    double ans = 0;
    scanf("%lld%lld", &n, &d); getchar();

    for (i64 i = 0; i < n; i++) {
        scanf("%lld", &(a[i].second));
    }
    for (i64 i = 0; i < n; i++) {
        scanf("%lf", &(a[i].first));
        a[i].first /= a[i].second;
    }
    sort(a, a + n, [](pair<double, i64>& x, pair<double, i64>& y){return x.first > y.first;});
    for (i64 i = 0; i < n && d; i++) {
        if (a[i].second <= d) {
            d -= a[i].second;
            ans += a[i].first * a[i].second;
        }
        else {
            ans += d * a[i].first;
            break;
        }
    }
    
    printf("%.2f", ans);
}
signed main() {
    solve();

    system("pause");
    return 0;
}
