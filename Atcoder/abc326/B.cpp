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
i64 a[N], b[N];

bool check(i64 n) {
    array<i64, 3> arr;
    for (i64 i = 0; i < 3; i++) {
        arr[i] = n % 10;
        n /= 10;
    }
    return arr[2] * arr[1] == arr[0];
}

void solve() {
    i64 n, m, t, ans = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = n; i < 999; i++) {
		if (check(i)) {printf("%lld", i);return;}
	}

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
