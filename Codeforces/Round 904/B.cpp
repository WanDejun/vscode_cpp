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
char str[N];
i64 a[N];

void solve() {
    i64 n, m, t = 0, cnt = 0, kk = 0, cnt0 = 0;;
    scanf("%lld", &n); getchar();
    char c = getchar();
	while (c != '\n' && c != '\0') {
        str[t++] = c;
        c = getchar();
    }
    for (i64 i = n - 1; i >= 0; i--) {
        if (str[i] == '0') a[kk++] = (n - 1 - i);
    }
    for (i64 i = 0; i < n; i++) {
        if (i >= kk) printf("-1 ");
        else {
            cnt += i;
            cnt0 += a[i];
            printf("%lld ", cnt0 - cnt);
        }
    }
    putchar('\n');
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
