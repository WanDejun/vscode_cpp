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
PII node[N], v1, v2;

bool vector_same(PII& a, PII& b) {
    return (a[0] * b[1] - a[1] * b[0] == 0);
}

i64 Area(PII& a, PII& b) {
    if (vector_same(a, b)) return LLONG_MAX;
    return abs(a[0] * b[1] - a[1] * b[0]);
}

void solve() {
    i64 n = 0, k, m = 0, t = 0, ans = LLONG_MAX, cnt = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld", &node[i][0], &node[i][1]);
	}
    for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < n; j++) if (j != i) {
            for (i64 k = 0; k < n; k++) if (k != i && k != j) {
                v1[0] = node[j][0] - node[i][0];
                v1[1] = node[j][1] - node[i][1];
                v2[0] = node[k][0] - node[i][0];
                v2[1] = node[k][1] - node[i][1];
                ans = min(ans, Area(v1, v2));
            }
        }
    }
	
    if (ans == LLONG_MAX) printf("-1\n");
	else printf("%.1lf\n", static_cast<double>(ans) / 2);
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
