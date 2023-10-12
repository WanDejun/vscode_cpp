#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long
#define i32 long

using namespace std;

const i64 N = 1e3 + 5;
const i64 MOD = 998244353;
char a[N][N];
i64 flag[26];
i64 loc[4][2], n;

void f(i64 x, i64 y) {
    loc[0][0] = x; loc[0][1] = y;
    loc[1][0] = y; loc[1][1] = n - 1 - x;
    loc[2][0] = n - 1 - x; loc[2][1] = n - 1 - y;
    loc[3][0] = n - 1 - y; loc[3][1] = x;
    //for (int i = 0; i < 4; i++) cout << loc[i][0] << " " << loc[i][1] << endl;
}
i64 cal() {
    i64 ans = 0;
    char maxc = 'a';
    for (int i = 0; i < 4; i++) {
        maxc = max(maxc, a[loc[i][0]][loc[i][1]]);
    }
    for (int i = 0; i < 4; i++) {
        ans += maxc - a[loc[i][0]][loc[i][1]];
    }
    //cout << maxi << endl;
    return ans;
}
void solve() {
    i64 m, t, ans = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < n; j++) {
            a[i][j] = getchar();
        }
        getchar();
    }
    for (i64 i = 0; i < (i64)(n / 2); i++) {
        for (i64 j = i; j < n - 1 - i; j++) {
            f(i, j);
            ans += cal();
        }
    }
	printf("%lld\n", ans);
}

int main() {
	i64 _;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
