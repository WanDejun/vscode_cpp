#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long

using namespace std;
const i64 N = 1e5 + 5;
i64 a[N], k;

void solve() {
    i64 n, ans = 0, t, pre = -1;
    scanf("%lld", &n);
    for (i64 i = 0; i < n; i++) {
        scanf("%lld", &t);
        if (t % 2) {
            a[k++] = t;
        }
        else ans += t;
    }
    sort(a, a + k, [](i64 a, i64 b) {
        return a > b;
    });
    for (i64 i = 0; i + 1 < k; i += 2) {
        ans += (a[i] + a[i + 1]);
    }
    cout << ans << endl;
} 

signed main() {
    solve();

	system("pause");

	return 0;
}