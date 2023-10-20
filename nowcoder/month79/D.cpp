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
    i64 n, ans = LLONG_MAX, t;
    scanf("%lld", &n); getchar();
    for (i64 i = 0; i <  n; i++) {
        scanf("%lld", &t);
        ans = LLONG_MAX;
        if (t == 0) cout << 0 << endl;
        else {
            for (i64 j = 0; j < 22; j++, t++) 
                ans = min(ans, 20 - min(static_cast<i64>(log(t & (-t)) / log(2)), 20ll) + j);
            cout << ans << endl;
        }
    }
} 

signed main() {
    solve();

	system("pause");

	return 0;
}