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

const i64 N = 1e2 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N];

void solve() {
    i64 n;
    scanf("%lld", &n); getchar();
    for (i64 i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    for (i64 i = 1; i <= n; i++) {
        b[i] = b[i - 1] + 1;
        if (b[i] == a[i]) b[i]++; 
        printf("%lld ", b[i]);
    }
}
signed main() {
    solve();

    system("pause");
    return 0;
}
