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
i64 first_appear[N], a[N];

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, col_cnt = 0, cnt = 0, col_cnt_less = 0;
    set<i64> S;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
        if (S.find(a[i]) == S.end()) {
            S.insert(a[i]);
            col_cnt++;
			first_appear[a[i]] = i;
        }
	}
    S.clear();
    for (i64 i = n - 1; i >= 0; i--) {
		if (first_appear[a[i]] == i) col_cnt_less++;
        if (S.find(a[i]) == S.end()) {
            cnt++;
            S.insert({a[i]});
            if (cnt == col_cnt) {
                ans++;   
                cnt = 0;
                S.clear();
				col_cnt -= col_cnt_less;
				col_cnt_less = 0;
            }
        }
    }
	
	printf("%lld\n", ans);
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
