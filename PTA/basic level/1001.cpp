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

const i64 N = 1e5 + 5;
const i64 MOD = 998244353;
i64 a[N];

bool check(i64 n) {
    for (i64 i = 2; i <= sqrt(n + 1); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    i64 n, ans = 0;
    scanf("%lld", &n); getchar();
    while (n != 1) {
        if (n % 2) n = (3 * n + 1) / 2;
        else n /= 2;
        ans++;
    }
    printf("%lld", ans);
}
signed main() {
    solve();

    system("pause");
    return 0;
}
