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
    i64 n, m, t, ans = 0;
    scanf("%lld", &n); getchar();
    if (!f) {
        for (i64 i = 3; i < n; i++) {
            t = a[i] + a[i - 1];
            a[i] = a[i] + a[i - 1] - 1;
            if (t % 3 == 0 && a[i] % (i64)(t / 3) == 0) a[i]++;
        }
    }

	printf("%s\n", ans ? "Yes" : "No");
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
