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
PII points[N];

void solve() {
    i64 n, m, t, ans = 0, maxi, id;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld", &points[i][0], &points[i][1]);
	}
	for (i64 i = 0; i < n; i++) {
		maxi = -1;
		for (i64 j = 0; j < n; j++) if (i != j){
			t = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
			if (t > maxi) {maxi = t; id = j;}
		}
		printf("%lld\n", id + 1);
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
