#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e3 + 5;
const i64 MOD = 998244353;
char a[N][N];

void solve() {
    i64 n = 0, k, m = 0, t = 0, ans = 0, cnt = 0;
    bool flag_W = 0, flag_B = 0;
    scanf("%lld%lld", &n, &m); getchar();
	for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < m; j++) {
            a[i][j] = getchar();
        }
        getchar();
	}
	
    bool f1 = 0, f2 = 0;
    char c1 = a[0][0], c2 = a[0][m - 1];
    for (i64 i = 1; i < n; i++) {
        if (a[i][0] != c1) f1 = 1;
        if (a[i][m - 1] != c2) f2 = 1;
    }
    if (f1 == 0 || n == 1) {
        if (c1 == 'W') flag_W = 1;
        else flag_B = 1;
    }

    if (f2 == 0 || n == 1) {
        if (c2 == 'W') flag_W = 1;
        else flag_B = 1;
    }

    f1 = 0, f2 = 0;
    c1 = a[0][0], c2 = a[n - 1][0];
    for (i64 i = 1; i < m; i++) {
        if (a[0][i] != c1) f1 = 1;
        if (a[n - 1][i] != c2) f2 = 1;
    }
    if (f1 == 0 || m == 1) {
        if (c1 == 'W') flag_W = 1;
        else flag_B = 1;
    }
    if (f2 == 0 || m == 1) {
        if (c2 == 'W') flag_W = 1;
        else flag_B = 1;
    }

    if (flag_W && flag_B) printf("NO\n");
	else printf("YES\n");
}

int main() {
	i64 _ = 1;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
