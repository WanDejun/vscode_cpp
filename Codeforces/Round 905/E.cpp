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
i64 a[N], b[N];
inline i64 cal(i64 a, i64 b) {
    i64 ans = 0;
    while (a > b) {
        ans++;
        b <<= 1;
    }
    return ans;
}
inline i64 cal_(i64 a, i64 b) {
    i64 ans = 0;
    while (a <= b) {
        ans++;
        a <<= 1;
    }
    return ans - 1;
}
void solve() {
    i64 n, m, t = 0, ans = 0, pre, nxt;
    scanf("%lld", &n); getchar();
    scanf("%lld", &pre);
	for (i64 i = 1; i < n; i++) {
		scanf("%lld", &nxt);
        if (nxt <= pre) {
            t += cal(pre, nxt);
        }
        else {
            t = max(t - cal_(pre ,nxt), 0ll);
        }
        ans += t;
        pre = nxt;
	}
	
	printf("%lld\n", ans);
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
