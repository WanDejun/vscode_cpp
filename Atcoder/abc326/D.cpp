#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 10;
const i64 MOD = 998244353;
char mx[N][N];
bool cnt_y[3][N];
string R, C;
void put() {
    printf("Yes\n");
    i64 n = R.length();
    for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < n; j++) {
            if (mx[i][j] == 0) putchar('.');
            else putchar(mx[i][j]);
        }
        putchar('\n');
    }
}
bool check() {
    i64 n = R.length();
    i64 i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mx[i][j] != 0) break;
        }
        if (mx[i][j] != R[i]) return false;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mx[j][i] != 0) break;
        }
        if (mx[j][i] != C[i]) return false;
    }
    return true;
}

void dfs(i64 deepth) {
    i64 n = R.length();
    for (i64 i = 0; i < n; i++) {
        if (!cnt_y[0][i]) cnt_y[0][i] = 1;
        else continue;
        mx[deepth][i] = 'A';

        for (i64 j = 0; j < n; j++) if (j != i) {
            if (!cnt_y[1][j]) cnt_y[1][j] = 1;
            else continue;
            mx[deepth][j] = 'B';

            for (i64 k = 0; k < n; k++) if (k != i && k != j) {
                if (!cnt_y[2][k]) cnt_y[2][k] = 1;
                else continue;

                mx[deepth][k] = 'C';
                if (deepth == n - 1) {
                    if (check()) {
                        put();

                        system("pause");
                        exit(0);
                    }
                }
                else dfs(deepth + 1);

                mx[deepth][k] = 0;
                cnt_y[2][k] = 0;
            }
            mx[deepth][j] = 0;
            cnt_y[1][j] = 0;
        }
        mx[deepth][i] = 0;
        cnt_y[0][i] = 0;
    }
}

void solve() {
    i64 n, m, t, ans = 0;
    scanf("%lld", &n); getchar();
    cin >> R >> C;
	dfs(0);
	
	printf("No");
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
