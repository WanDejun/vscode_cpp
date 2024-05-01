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
i64 h, w, n, t, ans = 0, x, y;
i64 MX[N][N], EN[N][N], OK_flag, DIS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, ST_EN[N][N];
stack<PII> ST_point;
map<PII, i64> M;

void dfs(PII, S, PII T) {
	ST_point[]
}

void solve() {
	PII S, T;
    scanf("%lld%lld", &h, &w); getchar();
	for (i64 i = 0; i < h; i++) {
		for (i64 j = 0; j < w; j++) {
			MX[i][j] = getchar();
			if (MX[i][j] == 'S') {
				S = {i, j};
			}
			else if (MX[i][j] == 'T') {
				T = {i, j};
			}
		}
		getchar();
	}

	scanf("%lld", &n);
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &x, &y, &t);
		M[{x - 1, y - 1}] = t;
	}

	dfs(S, T);
	
	printf("%s\n", OK_flag ? "Yes" : "No");
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
