#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define FI first
#define SE second
#define i64 long long
#define i32 long

using namespace std;

const i64 N = 1e2 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N];

void solve() {
    i64 n, x, y;
    bool f = 1;
    scanf("%lld", &n); getchar();
    scanf("%lld", &x);
    for (i64 i = 1; i < n; i++) {
        scanf("%lld", &y);
        if (x != y) f = 0;
    }
    printf("%s\n", f ? "Yes" : "No");
}
signed main() {
    solve();

    //system("pause");
    return 0;
}
