#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e3 + 5;
const i64 MOD = 998244353;
char mx[N][N];
bool illegal[N][N];
char dis[8][2] = {{0, 1}, {0, -1}, {1, 1}, {1, -1}, {1, 0}, {-1, 0}, {-1, 1}, {-1, -1}};

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
    scanf("%lld%lld", &n, &m); getchar();
	for (i64 i = 0; i <= n + 1; i++) {
		mx[i][0] = 'M';
		mx[i][m + 1] = 'M';
	}
    for (i64 i = 0; i <= m + 1; i++) {
		mx[0][i] = 'M';
		mx[n + 1][i] = 'M';
	}

    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            mx[i][j] = getchar();
        }
        getchar();
    }

    for (i64 i = 0; i <= n + 1; i++) {
        for (i64 j = 0; j <= m + 1; j++) {
            if (mx[i][j] == 'M') illegal[i][j] = 1;
            else if (mx[i][j] == 'H') {
                illegal[i][j] = 1;
                for (i64 k = 0; k < 8; k++) {
                    illegal[i + dis[k][0]][j + dis[k][1]] = 1;
                }
            }
        }
    }

    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            if (illegal[i][j]) continue;
            if (mx[i][j] == 'L' || mx[i][j] == 'S') {
                bool flag = 1;
                for (i64 k = 0; k < 8; k++) {
                    if (mx[i + dis[k][0]][j + dis[k][1]] != 'L' && mx[i + dis[k][0]][j + dis[k][1]] != 'S') { 
                        flag = 0;
                        break;
                    }
                }
                if (flag) mx[i][j] = 'S';
            }
        }
    }
	
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            if (illegal[i][j]) continue;
            if (mx[i][j] == 'G') {
                bool flag = 1;
                for (i64 k = 0; k < 8; k++) {
                    if (mx[i + dis[k][0]][j + dis[k][1]] == 'L' || mx[i + dis[k][0]][j + dis[k][1]] == 'S') { 
                        flag = 0;
                        break;
                    }
                }z
                if (flag) mx[i][j] = 'B';
                else mx[i][j] = 'N';
            }
        }
    }

	for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            putchar(mx[i][j]);
        }
        putchar('\n');
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
