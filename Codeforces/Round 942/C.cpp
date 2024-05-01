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
i64 a[N], n;

i64 cal(i64 num) {
    i64 cnt = 0;
    for (i64 i = 0; i < n; i++) {
        cnt += max(0ll, num - a[i]);
    }
    return cnt;
}

i64 BinarySearch(i64 key) {
    i64 l = 0, r = 2e12, mid, cnt;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        cnt = cal(mid);
        if (cnt > key)  r = mid - 1;
        else l = mid;
    }
    return l;
}

void solve() {
    i64 m = 0, k = 0, ans = 0, cnt = 0, t = 0;
    scanf("%lld%lld", &n, &k); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
	
    ans = BinarySearch(k);
    for (i64 i = 0; i < n; i++) {
        if (a[i] > ans) {
            t++;
        }
    }
    cnt = cal(ans);
    ans = (ans - 1) * n + 1 + k - cnt + t;

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
