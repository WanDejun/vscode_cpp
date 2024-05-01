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

void solve() {
    i64 n, t, ans = 0, a, c;
	map<i64, i64> m;

    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld", &a, &c);
		if (m.find(c) != m.end())
			m[c] = min(m[c], a);
		else 
			m[c] = a;
	}
	i64 maxi = -1;
	for (auto& it : m) {
		if (it.second > maxi) {
			maxi = it.second;
		}
	}
	
	printf("%lld\n", maxi);
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
