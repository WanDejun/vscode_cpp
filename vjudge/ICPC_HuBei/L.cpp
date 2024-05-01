/**
 * @problem: L
 */
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pii pair<i64, i64>

using namespace std;
LL a, b;

LL find(LL x) {
    for (LL i = 2; i <= sqrt(x) + 1; i++) {
        if (x % i == 0) return i;
    }
    return x;
}
void solve() {
    scanf("%lld%lld", &a, &b);
    if (a == b) {
        // printf("%lld\n", a);
        printf("0\n");
        return;
    }
    if (__gcd(a, b) != 1) {
        if (b % a == 0) { printf("%lld\n", b); }
        else { printf("%lld\n", a + b); }
    }
    else {
        LL x = find(a), y = find(b);
        LL ans = a + b + min(x * y, (x + y) << 1);
        if (x == a) ans -= x;
        if (y == b) ans -= y;
        ans = min(ans, (a + b) << 1);
        printf("%lld\n", ans);
    }
}
int main() {
    LL _ = 1;
    scanf("%lld", &_);
    getchar();
    for (LL __ = 0; __ < _; __++) solve();
    system("pause");
    return 0;
}