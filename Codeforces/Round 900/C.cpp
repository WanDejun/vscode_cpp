#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long
#define i32 long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
i64 a[N] = {2, 3, 4};
bool f = 0;

void solve() {
    i64 n, k, x;
    scanf("%lld%lld%lld", &n, &k, &x); getchar();
    i64 maxi = ((n + n + 1 - k) * k) / 2, mini = (1 + k) * k / 2;

    printf("%s\n", x >= mini && x <= maxi ? "Yes" : "No");
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
