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
string s;
i64 a[N], kk;

void solve() {
    i64 n, m, t, ans = 0, cnt = 0;
    kk = 0;
    scanf("%lld", &n); getchar();
    cin >> s;
    string s_ = s;
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
            if (s[i] == '1') {
                s = s.substr(0, i) + "01" + s.substr(i);
                j += 2;
                a[kk++] = i;
            }
            else {
                s = s.substr(0, j + 1) + "01" + s.substr(j + 1);
                a[kk++] = j + 1;
                j += 2;
            }
            ans++;
        }
    }
    printf("%lld\n", ans);
    for (i64 i = 0; i < kk; i++) {
        printf("%lld ", a[i]);
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
