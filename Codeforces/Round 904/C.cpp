#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 1e5 + 5;
const i64 MOD = 998244353;
i64 st[N], ed[N], a[2 * N], n, kk;
void init() {
    i64 i, j;
    sort(a, a + ((n + 1) << 1));
    for (i = 1, j = 1; i < ((n + 1) << 1); i++) {
        if (a[i] != a[i - 1]) {
            a[j++] = a[i];
        }
    }
    for (i = 0; i < n; i++) {
        st[i] = lower_bound(a, a + j, st[i]) - a;
        ed[i] = lower_bound(a, a + j, ed[i]) - a;
    }
    kk = j;
}
void solve() {
    i64 m, t = 0, ans = 0;
    bool c_pre = 0, c_end = 0;
    scanf("%lld%lld", &n, &m); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld", st + i, ed + i);
        st[i]--;
        a[i << 1] = st[i]; a[i << 1 | 1] = ed[i];
	}
    a[n << 1] = 0; a[n << 1 | 1] = m;
    init();
    memset(a, 0, sizeof a);
    for (i64 i = 0; i < n; i++) {
        if (st[i] == 0) c_pre = 1;
        if (ed[i] == kk - 1) c_end = 1;
        a[st[i]]++; a[ed[i]]--;
    }
    if (!c_pre || !c_end) {
        for (i64 i = 0; i < kk; i++) {
            t += a[i];
            ans = max(ans, t);
        }
    }
    else {
        for (i64 i = 0; i < n; i++) {
            if (st[i] == 0) {
                a[0]--; a[ed[i]]++;
            }
        }
        t = 0;
        for (i64 i = 0; i < kk; i++) {
            t += a[i]; ans = max(ans, t);
        }
        for (i64 i = 0; i < n; i++) {
            if (st[i] == 0) {
                a[0]++; a[ed[i]]--;
            }
            if (ed[i] == kk - 1) {
                a[st[i]]--; a[kk - 1]++;
            }
        }
        t = 0;
        for (i64 i = 0; i < kk; i++) {
            t += a[i]; ans = max(ans, t);
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
