#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
char      a[N], b[N];

void solve() {
    i64 n, cnt1 = 0, cnt0 = 0;
    char c;
    scanf("%lld", &n);
    getchar();
    for (i64 i = 0; i < n; i++) { a[i] = getchar(); }
    getchar();
    for (i64 i = 0; i < n; i++) {
        c = getchar();
        if (c != a[i]) {
            if (c == '0') cnt0++;
            else cnt1++;
        }
    }

    printf("%lld\n", max(cnt1, cnt0));
}

int main() {
    i64 _ = 1;
    scanf("%lld", &_);
    getchar();
    for (i64 __ = 0; __ < _; __++) { solve(); }
    system("pause");

    return 0;
}
