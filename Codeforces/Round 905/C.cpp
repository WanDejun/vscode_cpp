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
i64 c[4];

void solve() {
    i64 n, m, t, k, ans = 0, maxi = -1, c1 = 0;
    bool flag = 0;
    scanf("%lld%lld", &n, &k); getchar();
    memset(c, 0, sizeof c);
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", &t); t %= k;
        maxi = max(maxi, t);
        c[t]++;
        if (t == 0) flag = 1;
	}
    if (k == 1) {printf("0\n");}
	else if (k == 4) {
        if (flag || c[2] >= 2) printf("0\n");
        else if (c[1] + c[2] >= 2) printf("%lld\n", min(k - maxi, 2 - c[2])); 
        else printf("%lld\n", k - maxi);
    }
	else printf("%lld\n", flag ? 0 : k - maxi);
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
