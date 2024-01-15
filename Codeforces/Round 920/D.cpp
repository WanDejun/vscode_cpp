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
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
    scanf("%lld%lld", &n, &m); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
	
    for (i64 i = 0; i < m; i++) {
        scanf("%lld", b + i);
    }
     
    sort(a, a + n);
    sort(b, b + m, [](i64 x, i64 y) {return x > y;});

    for (i64 i1 = 0, i2 = 0, j1 = n - 1, j2 = m - 1; i1 <= j1; ) {
        i64 t1 = abs(a[i1] - b[i2]), t2 = abs(a[j1]  - b[j2]);
        if (t1 > t2) {
            cnt += t1;
            i1++;
            i2++;
        }
        else {
            cnt += t2;
            j1--;
            j2--;
        }
    }

	printf("%lld\n", cnt);
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
