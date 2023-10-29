// https://atcoder.jp/contests/arc134/tasks/arc134_d
#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 1e5 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N], c[N << 1], d[N << 1], kc, kd;

void solve() {
    i64 n, m, t, ans = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
    for (i64 i = 0; i < n; i++) {
		scanf("%lld", b + i);
	}

    i64 mina = a[n - 1];
    for (i64 i = n - 2; i >= 0; i--) {
        if (a[i] > mina) {a[i] = -1; b[i] = -1;}
        else mina = a[i];
    }
    m = 0;
	for (i64 i = 0; i < n; i++) {
        if (a[i] != -1) {
            a[m] = a[i];
            b[m] = b[i];
            m++;
        }
    }

    t = upper_bound(a, a + m, a[0]) - a;
    i64 mini = LLONG_MAX;
    for (i64 i = 0; i < t; i++) {
        mini = min(mini, b[i]);
    }
    if (mini <= a[0]) {printf("%lld %lld\n", a[0], mini); return;}
    
    //if (m == 1) {printf("%lld %lld\n", a[0], b[0]);return;}

    t = lower_bound(a, a + m, b[0]) - a;
    for (i64 i = 0; i < t; i++) c[kc++] = a[i];
    for (i64 i = 0; i < t; i++) c[kc++] = b[i];

    t = upper_bound(a, a + m, b[0]) - a;
    for (i64 i = 0; i < t; i++) d[kd++] = a[i];
    for (i64 i = 0; i < t; i++) d[kd++] = b[i];

    i64 flag = -1;
    for (i64 i = 0; i < kc; i++) {
        if (d[i] < c[i]) {flag = 1; break;}
        else if (d[i] > c[i]) {flag = 0; break;}
    }
    if (flag == -1) flag = 0;
    if (flag) 
        for (i64 i = 0; i < kd; i++) printf("%lld ", d[i]);
    else
        for (i64 i = 0; i < kc; i++) printf("%lld ", c[i]);
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
