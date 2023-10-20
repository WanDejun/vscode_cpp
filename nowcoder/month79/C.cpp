#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long

using namespace std;
const i64 N = 1e5 + 5;
i64 a[N];

void solve() {
    i64 n, ans = 0, t;
    bool flag = 0, flag_ = 0;
    scanf("%lld", &n);
    for (i64 i = 0; i < n; i++) {
        scanf("%lld", a + i);
    }

    for (i64 i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (i != 0) ans = max(ans, a[i - 1]);
            if (i + 1 < n) ans = max(ans, a[i + 1]);
            flag = 1;
        }
        else flag_ = 1;
    }
    if (!flag || !flag_) {cout << 0 << endl; return;}
    sort(a, a + n);
    a[n] = LLONG_MAX;
    for (i64 i = 1; i <= n; i++) {
        if (a[i] - a[i - 1] > 1) {
            ans = max(ans, a[i - 1] + 1);
            break;
        }
    }
    cout << ans << endl;
} 

signed main() {
    solve();

	system("pause");

	return 0;
}