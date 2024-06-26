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

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0, k;
    scanf("%lld%lld", &n, &k); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld", &a[i][0], &a[i][1]);
	}
    sort(a, a + n, [&](PII& a, PII& b) {
        return a[0] < b[0];
    });
    
    if (a[0][1] > k * a[0][0]) {
        printf("No\n");
        return;
    }
    for (i64 i = 1; i < n; i++) {
        a[i][1] += a[i - 1][1];
        if (a[i][1] > k * a[i][0]) {
            printf("No\n");
            return;
        }
    }
	
	printf("Yes\n");
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
