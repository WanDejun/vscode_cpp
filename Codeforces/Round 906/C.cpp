#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e2 + 5;
const i64 MOD = 998244353;
char s[N];
i64 kk;
PII a[N];

void solve() {
    i64 n, m, t, ans = 0, cnt = 0;
    scanf("%lld", &n); getchar();
    kk = 0;
	scanf("%s", s);
    if (n & 1) {printf("-1\n"); return;}

    for (i64 i = 0; i < n; i++) {
        if (s[i] == '1') cnt++;
    }
    if (cnt != n / 2) {printf("-1\n"); return;}

    bool f = 0;
    for (i64 i = 0, j = n - 1; i < j && !f; i++, j--) { //特判
        if (s[i] == s[j]) f = 1;
    }
    if (!f) {printf("0\n\n"); return;}

    for (i64 i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] == s[j]) {
            if (s[i] == '1') {printf("-1\n"); return;}
            else {
                a[kk][0] = j + 1;
                if (kk > 0 && j - (a[kk -  1][0] - 1) == 1) a[kk][1] = a[kk - 1][1] + 1;
                kk++;
                s[j + 1] = '0'; j += 2;
            }
        }
    }
    printf("%lld\n", kk);
    sort(a, a + kk, [](PII& a, PII& b) {return a[0] < b[0];});

	for (i64 i = 0; i < kk; i++) {
        printf("%lld ", a[i][0] + 2 * (i - a[i][1]));
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
