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
i64 score[N], m, ans, n;
PII a[N];

void dfs(i64 deepth) {
    if (deepth == m) {
        i64 cnt = 0;
        for (i64 i = 1; i < n; i++) {
            if (score[i] > score[0]) cnt++;
        }
        ans = min(ans, cnt);
    }
    else {
        score[a[deepth][0] - 1] += 3;
        dfs(deepth + 1);
        score[a[deepth][0] - 1] -= 3;

        score[a[deepth][1] - 1] += 3;
        dfs(deepth + 1);
        score[a[deepth][1] - 1] -= 3;

        score[a[deepth][0] - 1]++;
        score[a[deepth][1] - 1]++;
        dfs(deepth + 1);
        score[a[deepth][0] - 1]--;
        score[a[deepth][1] - 1]--;
    }
}

void solve() {
    i64 t = 0, k = 0;
    ans = LLONG_MAX;
    scanf("%lld%lld", &n, &m); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", score + i);
	}
	for (i64 i = 0; i < m; i++, k++) {
        scanf("%lld%lld", &(a[k][0]), &(a[k][1]));
        if (a[k][0] == 1 || a[k][1] == 1) {
            k--;
            score[0] += 3;
        }
    }
    m = k;
    dfs(0);

	printf("%lld\n", ans + 1);
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
