// https://codeforces.com/problemset/problem/1443/C
#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
PII a[N];

void solve() {
    i64 n, m, t = 0, ans = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) scanf("%lld", &(a[i][0]));
	for (i64 i = 0; i < n; i++) scanf("%lld", &(a[i][1]));
    sort(a, a + n, [](PII& a, PII& b) {return a[0] > b[0];});
	for (i64 i = 0; i < n; i++) {
        if (t + a[i][1] < a[i][0]) {
            t += a[i][1];
        }
        else {
            ans = a[i][0];
            break;
        }
    }
	printf("%lld\n", max(t, ans));
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
