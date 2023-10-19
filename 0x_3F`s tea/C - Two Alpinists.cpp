// https://atcoder.jp/contests/code-festival-2016-qualc/tasks/codefestival_2016_qualC_c
#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 1e5 + 5;
const i64 MOD = 1e9 + 7;
i64 a[N], b[N];

void solve() {
    i64 n, m, t, ans = 1;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) scanf("%lld", a + i);
    for (i64 i = 0; i < n; i++) scanf("%lld", b + i);
    bool f1, f2;
    for (i64 i = 0; i < n; i++) {
        f1 = f2 = 0;
        if (i == 0 || a[i] > a[i - 1]) f1 = 1;
        if (i == n - 1 || b[i] > b[i + 1]) f2 = 1;
        if (f1 == 1 && f2 == 1) {
            if (a[i] != b[i]) {printf("0\n"); return;}
        }
        else if (f1 == 1) {
            if (a[i] > b[i]) {printf("0\n"); return;}
        }
        else if (f2 == 1) {
            if (a[i] < b[i]) {printf("0\n"); return;}
        }
        else {
            (ans *= min(a[i], b[i])) %= MOD;
        }
    }
	
	printf("%lld\n", ans);
}

int main() {
	i64 _ = 1;
	//scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
