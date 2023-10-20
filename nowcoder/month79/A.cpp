#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long

using namespace std;
const i64 N = 1e5 + 5;

void solve() {
    i64 n, ans = 0, t, pre = -1;
    scanf("%lld", &n);
    for (i64 i = 0; i < n; i++) {
        scanf("%lld", &t);
        if (t % 2) {
            if (pre != -1) {
                ans += (pre + t);
                pre  = -1;
            }
            else pre = t;
        }
        else ans += t;
    }
    cout << ans << endl;
} 

signed main() {
    solve();

	system("pause");

	return 0;
}