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
char a[N], b[N];
void solve() {
    i64 n, m, t, ans = 0;
    scanf("%lld%lld", &n, &m); getchar();
	scanf("%s", a); getchar();
    scanf("%s", b); getchar();
    bool f1 = 0, f2 = 0;
	for (i64 i = 1; i < n; i++) {
        if (a[i] == a[i - 1]){
            if (a[i] == '1') {
                if (f2) {printf("No\n"); return;}
                f1 = 1;
            }
            else {
                if (f1) {printf("No\n"); return;}
                f2 = 1;
            }
        }

    }
    if (!f1 && !f2) {printf("Yes\n"); return;}
    for (i64 i = 1; i < m; i++) {
        if (b[i] == b[i - 1]) {printf("No\n"); return;}
    }
    if (b[0] != b[m - 1]) {printf("No\n"); return;}
    if (f1 && b[0] == '1') {printf("No\n"); return;}
    if (f2 && b[0] == '0') {printf("No\n"); return;}
	printf("Yes\n");
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
