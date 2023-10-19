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

const i64 N = 1e3 + 5;
const i64 MOD = 998244353;
i64  a[N][N], xs[N] ,ys[N], ans[N], kk;

void solve() {
    i64 n, m, tol, loc = -1;
    map<i64, i64> cnt;
    scanf("%lld%lld%lld", &m, &n, &tol);
    for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < m; j++) {
            scanf("%lld", &(a[i][j]));
            cnt[a[i][j]]++;
        }
    }
    for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < m; j++) {
            bool f = 1;
            for (i64 x = i - 1; x <= i + 1 && f; x++) {
                if (x < 0 || x >= n) continue;
                for (i64 y = j - 1; y <= j + 1 && f; y++) {
                    if (y < 0 || y >= m) y++;
                    if (x == i && y == j) continue;
                    if (abs(a[x][y] - a[i][j]) <= tol) f = 0;
                }
            }
            if (f) {ans[kk] = a[i][j]; xs[kk] = i; ys[kk] = j; kk++;}
        }
    }
    
    for (i64 i = 0; i < kk; i++) {
        if (cnt[ans[i]] == 1) {
            if (loc == -1) {
                loc = i;
            }
            else {
                printf("Not Unique\n");
                return;
            }
        }
    }
    if (loc == -1) {
        printf("Not Exist\n");
    }
    else printf("(%lld, %lld): %lld\n", ys[loc] + 1, xs[loc] + 1, ans[loc]);
}
signed main() {
    solve();

    system("pause");
    return 0;
}
