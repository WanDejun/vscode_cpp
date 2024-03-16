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
i64 a[10][3] = {
{1,2,3},
{1,3,2},
{2,1,3},
{2,3,1},
{3,1,2},
{3,2,1},
{1,1,1},
{1,1,2},
{1,2,1},
{2,1,1}
};
i64 b[N][3];

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0, flag = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &(b[i][0]), &(b[i][1]), &(b[i][2]));
		b[i][0]--;
		b[i][1]--;
	}
	
	for (i64 i = 0; i < 10 && flag == 0; i++) {
		i64 j;
		for (j = 0; j < n; j++) {
			if (b[j][2]) {
				if (a[i][b[j][0]] <= a[i][b[j][1]]) break;
			}
			else {
				if (a[i][b[j][0]] > a[i][b[j][1]]) break;
			}
		}
		if (j == n) flag = 1;
	}

	if (flag) printf("Yes\n");
	else printf("No\n");
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
