#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 1e9 + 7;
i64       a[N], b[N];

i64 qpow(i64 a, i64 n) {
    i64 ans = 1;
    while (n) {
        if (n & 1)              // 如果n的当前末位为1
            (ans *= a) %= MOD;  // ans乘上当前的a
        (a *= a) %= MOD;        // a自乘
        n >>= 1;                // n往右移一位
    }
    return ans;
}

void solve() {
    i64 n = 0, k = 0, t = 0, ans = 0, cnt = 0, sum = 0, maxi = 0;
    scanf("%lld%lld", &n, &k);
    getchar();
    for (i64 i = 0; i < n; i++) {
        scanf("%lld", a + i);
        sum += a[i];
        t += a[i];
        maxi = max(maxi, t);
        if (t < 0) { t = 0; }
    }

    while (sum < 0) sum += MOD;

    if (maxi > 0) { (sum += ((qpow(2, k) - 1) % MOD) * (maxi % MOD)) %= MOD; }

    printf("%lld\n", sum);
}

int main() {
    i64 _ = 1;
    scanf("%lld", &_);
    getchar();
    for (i64 __ = 0; __ < _; __++) { solve(); }
    system("pause");

    return 0;
}
