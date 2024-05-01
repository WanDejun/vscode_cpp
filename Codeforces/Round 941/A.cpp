#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e2 + 5;
const i64 MOD = 998244353;
i64 a[N];

void solve() {
    i64 n = 0, k, m = 0, t = 0, ans = 0, cnt = 0;
    scanf("%lld%lld", &n, &k); getchar();
    for (i64 i = 0; i <= 200; i++) {
        a[i] = 0;
    }
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", &t);
        a[t]++;
	}
    sort(a, a + 200, [](i64 a, i64 b) {return a>b;});

    for (i64 i = 0; i <= 200; i++) {
        if (a[i] + cnt >= k) cnt = a[i] + cnt - 1;
        else {
            ans = cnt;
            for (i64 j = i; j <= 200; j++) {
                ans += a[j];
            }
            break;
        }
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
