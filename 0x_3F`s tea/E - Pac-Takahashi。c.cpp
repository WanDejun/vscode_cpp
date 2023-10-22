// https://atcoder.jp/contests/abc301/tasks/abc301_e (Error)
#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 3e2 + 5;
const i64 MOD = 998244353;
char mx[N][N];
i64 cnts[N][N], way[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve() {
    i64 h, w, t, ans = 0;
    i64 st_x, st_y, en_x, en_y, x, y, len;
    queue<array<i64, 3>> Q1, Q2; // x, y, len
    scanf("%lld%lld%lld", &n, &m, &t); getchar();
	for (i64 i = 1; i <= h ; i++) {
		for (i64 j = 1; j <= w; j++) {
            mx[i][j] = getchar();
        }
	}
    for (i64 i = 0; i <= h; i++) {
        mx[h][0] = mx[h][w + 1] = '#';
    }
    for (i64 i = 0; i <= w; i++) {
        mx[0][i] = mx[h + 1][i] = '#';
    }
	Q1.push({st_x, st_y, 0});
    for (i64 i = 0; i < t; i++) {

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
