#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long
#define i32 long

using namespace std;

const i64 N = 2e2 + 5;
const i64 MOD = 998244353;
i64 L[N], R[N], X[N], col[N];
bool flag[N];
char str[N];
bool f = 0;

void solve() {
    i64 n, k, q, t;
    scanf("%lld%lld", &n, &k); getchar();
    for (i64 i = 0 ; i < n; i++) {
        str[i] = getchar();
    } getchar();
    for (i64 i = 0; i < n; i++) flag[i] = 0;
    for (i64 i = 0; i < k; i++) scanf("%lld", L + i);
    for (i64 i = 0; i < k; i++) scanf("%lld", R + i);
    scanf("%lld", &q);
    for (i64 i = 0; i < q; i++) {scanf("%lld", X + i); X[i]--; }

    for (i64 i = 0; i < k; i++) {
        L[i]--; R[i]--;
        for (i64 j = L[i]; j <= R[i]; j++) col[j] = i;
    }
    i64 l, r;
    for (i64 i = 0; i < q; i++) {
        t = L[col[X[i]]] + R[col[X[i]]] - X[i];
        l = min(X[i], t); r = max(X[i], t);
        flag[l] ^= 1; flag[r] ^= 1;
    }
    for (i64 i = 0; i < k; i++) {
        for (i64 j = L[i] + 1, k = R[i] - 1; j < k; j++, k--) {
            flag[j] ^= flag[j - 1]; flag[k] ^= flag[k + 1];
        }
        for (i64 j = L[i]; j <= R[i]; j++) {
            if (flag[j]) putchar(str[L[i] + R[i] - j]);
            else putchar(str[j]);
        }
    }
    putchar('\n');
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
