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
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
	map<i64, i64> M; 
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", &t);
		M[t]++;
	}

	if (M.find(3) != M.end() && M.find(6) != M.end()) ans += M[3] * M[6];
	if (M.find(10) != M.end() && M.find(8) != M.end()) ans += M[10] * M[8];
	if (M.find(7) != M.end() && M.find(2) != M.end()) ans += M[7] * M[2];

	printf("%lld\n", ans);
}

int main() {
	i64 _ = 1;
	// scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
