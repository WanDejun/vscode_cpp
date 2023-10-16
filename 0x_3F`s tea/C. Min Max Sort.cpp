#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 6e5 + 5;
const i64 MOD = 998244353;
i64 a[N];


void solve() {
    i64 n, t, k;
    scanf("%lld", &n); getchar();
    i64 x = n / 2, y = n + 1 - x, z = n - x, ans = n / 2;
    i64 l, r, m;
    for (i64 i = 0; i < n; i++) {
        scanf("%lld", a + i);
        if (a[i] == x) l = i;
        if (a[i] == y) r = i;
        if (a[i] == z) m = i;
    }
    //cout << l << r << endl;
    if ((n % 2 == 0 && l >= r) || (n % 2 && (l > m || m > r || l > r)) || n == 1) { 
        printf("%lld\n", ans); return; 
    }
    x--; y++;
    i64 cntl = 1, cntr = 1;
    for (i64 i = l - 1; i >= 0; i--) {
        if (a[i] == x) {
            x--;
            cntl++;
        }
    }
    for (i64 i = r + 1; i < n; i++) {
        if (a[i] == y) {
            y++;
            cntr++;
        }
    }
    cout << ans - min(cntl, cntr) << endl;
}

int main() {
	i64 _;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
