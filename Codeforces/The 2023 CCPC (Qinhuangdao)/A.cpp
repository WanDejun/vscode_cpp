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

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0, k;
    scanf("%lld%lld", &n, &k); getchar();
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d %d\n", i + 1, (i + j) % n + 1);
        }
    }
    int val = 2 * n + 1;
    for (int i = 0; i < n; i++)  {
        for (int j = 0; j < n; j++) {
            if (j == i || j == (i + 1) % n) continue;
            if (val == k + 1) return;
            printf("%d %d\n", i + 1, j + 1);
            val++;
        }
    }
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
