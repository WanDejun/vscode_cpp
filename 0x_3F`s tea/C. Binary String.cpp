#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5, K = 1e3 + 5;
const i64 MOD = 998244353;
i64 a[K];


void solve() {
    i64 n, ans = 0, t, k;
    scanf("%lld%lld", &n, &k); getchar();
    for (i64 i = 0; i < k; i++) {
        a[i] = 0;
    }
    for (i64 i = 0; i < n; i++) {
        scanf("%lld", &t);
        ans += t / k;
        a[t % k]++;
    }
    i64 i, j;
    for (i = 1, j = k - 1; i < j; ) {
        t = min(a[i], a[j]);
        ans += t;
        a[i] -= t; a[j] -= t;
        if (a[i] == 0) {
            i++;
        }
        else {
            if (i + j > k) {
                j--;
            }
            else {i++;j--;}
        }
    }
    if (i == j) ans += a[i] / 2;
    cout << ans << endl;
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
