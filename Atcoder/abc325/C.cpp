#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 1e3 + 5;
const i64 MOD = 998244353;
char mx[N][N];
bool vis[N][N];
i64 dis[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void solve() {
    i64 n, m, t, ans = 0;
    scanf("%lld%lld", &n, &m); getchar();
	for (i64 i = 0; i < n; i++) {
		for (i64 j = 0; j < m; j++) {
			mx[i][j] = getchar();
		}
		getchar();
	}
	queue<PII> q;
	for (i64 i = 0; i < n; i++) {
		for (i64 j = 0; j < m; j++) {
			if (mx[i][j] == '#' && !vis[i][j]) {
				q.push({i, j});
				vis[i][j] = 1;
				while (!q.empty()) {
					i64 x = q.front()[0], y = q.front()[1]; q.pop();
					for (i64 k = 0; k < 8; k++) {
						i64 xx = x + dis[k][0], yy = y + dis[k][1];
						if (xx >= 0 && xx < n && yy < m && yy >= 0 && mx[xx][yy] == '#' && !vis[xx][yy]) {
							q.push({xx, yy});
							vis[xx][yy] = 1;
						}
					}
				}
				ans++;
			}
		}
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
