#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e2 + 5;
const i64 MOD = 998244353;
i64 dp[N][10];
char l[N], r[N];

void init() {
    for (i64 i = 1; i < 10; i++) dp[1][i]= 1;
    for (i64 i = 2; i < N; i++) {
        for (i64 j = 0; j < 10; j++) {
            for (i64 k = 1; k < 10; k++) { // 第i位数
                (dp[i][j] += dp[i - 1][(j + 10 - k) % 10]) %= MOD;
            }
        }
    }
}
void solve() {
    i64 n, m, t, ans = 0;
    scanf("%s%s", &l, &r); getchar();
	n = strlen(l); m = strlen(r), t = m - n;
    init();
    for (i64 i = m; i >= t; i--) { 
        l[i] = l[i - t];
    }
    t = 0;
    for (i64 i = 0; i < m; i++) { // st
        if (l[i] == '0') continue;
        for (i64 j = l[i] - '0' + 1; j < 10; j++) {
            (ans += dp[m - i - 1][(20 - t - j) % 10]) %= MOD;
        }
        (t += (l[i] - '0')) %= 10;
    }
    
    t = 0;
    for (i64 i = 0; i < m; i++) { // ed
        for (i64 j = 1; j < r[i] - '0'; j++) {
            (ans += dp[m - i - 1][(20 - t - j) % 10]) %= MOD;
        }
        (t += (r[i] - '0')) %= 10;
    }
    for (i64 i = l[0] - '0' + 1; i < r[0] - '0'; i++) (ans += dp[m - 1][(10 - i) % 10]) %= MOD;
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
