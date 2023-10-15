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
    scanf("%lld", &n); getchar();
    while (n % 2 == 0) n >>= 1;
    while (n % 3 == 0) n /= 3;
    printf("%s\n", n != 1 ? "No" : "Yes");
}
signed main() {
    solve();

    //system("pause");
    return 0;
}
