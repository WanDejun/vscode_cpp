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
i64 dis[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve() {
    i64 n = 0, m = 0, k = 0, ans = 0, cnt = 0, a, b;
	set<PII> S;
    scanf("%lld%lld%lld", &n, &m, &k); getchar();
	for (i64 i = 0; i < k; i++) {
		scanf("%lld%lld", &a, &b);
		S.insert({a, b});
	}
	for (auto& it : S) {
		for (i64 i = 0; i < 4; i++) {
			if (S.find({it[0] + dis[i][0], it[1] + dis[i][1]}) != S.end()) cnt++;
		}
	}
	
	printf("%lld\n", k * 4 - cnt / 2);
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
