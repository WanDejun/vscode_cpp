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
i64 a[N], b[N];

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0, mini = 0;
    i64 maxi = -1, pre = 0;
    scanf("%lld", &n); getchar();
    scanf("%lld", &pre);
    maxi = pre;
	for (i64 i = 1; i < n; i++) {
		scanf("%lld", &t);
        if (t < pre) {
            if (maxi != 0) {
                ans += (maxi - mini);
                mini = maxi;
                maxi = 0;
            }
        }
        else {
            maxi = max(maxi, t);
        }
        pre = t;
        mini = min(t, mini);
	}
	if (maxi != 0) ans += (maxi - mini);
	printf("%lld\n", ans - 1);
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
