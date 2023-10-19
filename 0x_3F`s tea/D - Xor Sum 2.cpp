// https://atcoder.jp/contests/abc098/tasks/arc098_b 
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
i64 pre_one[21];

void solve() {
    for (i64 i = 0; i <= 20; i++) pre_one[i] = -1;
    i64 n, m, t, ans = 0, pre = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", &t);
        for (i64 j = 0; j <= 20 && t; j++) {
            if (t & 1) {
                pre = max(pre, pre_one[j] + 1);
                pre_one[j] = i;
            }
            t >>= 1;
        }
        ans += i - pre + 1; 
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
