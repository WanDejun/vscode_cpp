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
    i64 n, m, t, ans = 0, loc, cnt_pre = 0;
    bool flag = 0;
    scanf("%s%s", &l, &r); getchar();
	n = strlen(l); m = strlen(r), t = m - n;
    loc = m - 1;
    for (i64 i = 0; i < n; i++) if (l[i] != r[i]) {loc = i; break;}
    init();
    for (i64 i = m; i >= t; i--) { 
        l[i] = l[i - t];
    }
    for (i64 i = 0; i < loc; i++) {
        (cnt_pre += l[i] - '0') %= 10;
    }

    (t = cnt_pre + l[loc] - '0') %= 10;
    for (i64 i = loc + 1; i < m; i++) { // st
        if (i < (m - n)) continue;
        for (i64 j = l[i] - '0' + 1; j < 10; j++) {
            if (m - i - 1 == 0) (ans += ((t + j) % 10 == 0 ? 1 : 0)) %= MOD;
            else (ans += dp[m - i - 1][(20 - t - j) % 10]) %= MOD;
        }
        (t += (l[i] - '0')) %= 10;
    }
    
    t = cnt_pre + r[loc] - '0';
    for (i64 i = loc + 1; i < m; i++) { // ed
        for (i64 j = 1; j < r[i] - '0'; j++) {
            if (m - i - 1 == 0) (ans += ((t + j) % 10 == 0 ? 1 : 0)) %= MOD;
            else (ans += dp[m - i - 1][(20 - t - j) % 10]) %= MOD;
        }
        (t += (r[i] - '0')) %= 10;
    }
    for (i64 i = l[loc] - '0' + 1; i < r[loc] - '0'; i++) (ans += dp[m - loc][(20 - cnt_pre - i) % 10]) %= MOD;
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
