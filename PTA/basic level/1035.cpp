#include <bits/stdc++.h>

#define pii array<i64, 2>
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
i64  a[N], b[N], c[N];

bool cmp(i64* a1, i64* a2, i64 n) {
    for (i64 i = 0; i < n; i++) {
        if (a1[i] != a2[i]) return false;
    }
    return true;
}

void solve() {
    i64 n, p, ans = 0;
    bool finish = 0;
    scanf("%lld", &n); getchar();
    for (i64 i = 0; i < n; i++) {scanf("%lld", a + i); c[i] = a[i];}
    for (i64 i = 0; i < n; i++) scanf("%lld", b + i);

    for (i64 i = 1; i < n; i++) {
        for (i64 j = i; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                i64 t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
            }
        }
        if (cmp(a, b, n)) {
            i++;
            for (i64 j = i; j > 0; j--) {
                if (a[j] < a[j - 1]) {
                    i64 t = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = t;
                }
            }
            printf("Insertion Sort\n");
            for (i64 i = 0; i < n - 1; i++) {
                printf("%lld ", a[i]);
            }
            printf("%lld\n", a[n - 1]);
            return;
        }
    }
    for (i64 d = 2; d < n; d <<= 1) {
        for (i64 i = 0, j = i + d; i < n; i = j, j = j + d) {
            sort(c + i, c + min(j, n));
        }
        if (cmp(b, c, n)) {
            d <<= 1;
            for (i64 i = 0, j = i + d; i < n; i = j, j = j + d) {
                sort(c + i, c + min(j, n));
            }  
            printf("Merge Sort\n");
            for (i64 i = 0; i < n - 1; i++) {
                printf("%lld ", c[i]);
            }
            printf("%lld\n", c[n - 1]);
            return;
        }
    }
    
}
signed main() {
    solve();

    system("pause");
    return 0;
}
