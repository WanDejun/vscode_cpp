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
PII a[N];
i64 b[N], c[N];

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0, x;
    scanf("%lld%lld", &n, &x); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", &a[i][0]);
        a[i][1] = i;
	}
	for (i64 i = 0; i < n; i++) {
        scanf("%lld", b + i);
    }
    sort(a, a + n, [] (PII& a, PII& b) {return a[0] > b[0];});
    sort(b, b + n, [](i64 a, i64 b){ return a > b; });

    for (i64 i = 0, j = n - x; i < x; i++, j++) {
        if (a[i][0] <= b[j]) {printf("No\n"); return;}
        c[a[i][1]] = b[j];
    }
    for (i64 i = x, j = 0; i < n; i++, j++) {
        if (b[j] < a[i][0]) {printf("No\n"); return;}
        c[a[i][1]] = b[j];
    }

    printf("Yes\n");
    for (i64 i = 0; i < n; i++) {
        printf("%lld ", c[i]);
    }
    putchar('\n');
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
