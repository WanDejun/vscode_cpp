// https://codeforces.com/problemset/problem/750/C
#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
const i64 INF = 1ll << 32;
// i64 a[N], b[N];
bool adjust(i64& up, i64& low, i64 d) {
    if (d == 1) {
        if (up < 1900) return false;
        else low = max(1900ll, low);
    }
    else {
        if (low >= 1900) return false;
        else up = min(up, 1899ll);
    }
    return true;
}

void solve() {
    i64 n, m, t, ans = 0;
    scanf("%lld", &n); getchar();
    i64 up = INF, low = -INF, c, d;
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld", &c, &d);
        if (!adjust(up, low, d) || low > up) {
            cout << "Impossible" << endl;
            return;
        }
        if (up != INF) up += c; 
        if (low != -INF) low += c;
	}
	if (up == INF) cout << "Infinity" << endl;
	else printf("%lld\n", up);
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
