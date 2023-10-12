#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long
#define i32 long

using namespace std;

const i64 N = 1e2;
const i64 MOD = 998244353;
i64 a[N][N], b[N], c[N];

void solve() {
    i64 a, b, c, t;
    scanf("%lld%lld%lld", &a, &b, &c); getchar();
	t = __gcd(a, __gcd(b, c));
    i64 cnt = a / t + b / t + c / t - 3;
	printf("%s", cnt <= 3 ? "Yes\n" : "No\n");
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
