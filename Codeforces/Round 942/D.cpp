#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e6 + 5;
const i64 MOD = 998244353;
i64       a[N], prime[N], kk;

bool check(i64 a, i64 b) {
    return (a + b) % (b * b) == 0;
}

void solve() {
    i64 n = 0, k, m = 0, t = 0, ans = 0, cnt = 0;
    scanf("%lld%lld", &n, &m);
    getchar();
    ans = n;
    for (i64 i = 2; i <= m; i++) {
        for (i64 k = 1; i * k <= n; k++) {
			if (check(i * k, i)) ans++;
		}
    }

    printf("%lld\n", ans);
}

int main() {
    i64 _ = 1;
    scanf("%lld", &_);
    getchar();
    for (i64 __ = 0; __ < _; __++) { solve(); }

    system("pause");
    return 0;
}
