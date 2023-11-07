// https://codeforces.com/problemset/problem/777/C
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
//i64 a[N], b[N];

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0, st, ed;
    scanf("%lld%lld", &n, &m); getchar();
    vector<vector<i64>> a(n, vector<i64>(m)), b(n, vector<i64>(m));
    vector<i64> c(n);
	for (i64 i = 0; i < n; i++) {
		for (i64 j = 0; j < m; j++) {
            scanf("%lld", &a[i][j]);
        }
	}
    for (i64 i = 0;i < m; i++) {
        for (st = 0, ed = 1; ed < n; ed++) {
            if (a[ed][i] < a[ed - 1][i]) st = ed;
            b[ed][i] = st;
        } 
    }
    for (i64 i = 0; i < n; i++) c[i] = *min_element(b[i].begin(), b[i].end());

    scanf("%lld", &t);
	for (i64 i = 0; i < t; i++) {
        scanf("%lld%lld", &st, &ed);
        st--; ed--;
        if (c[ed] > st) printf("No\n");
        else printf("Yes\n");
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