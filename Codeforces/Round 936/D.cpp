#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e6 + 5;
const i64 MOD = 998244353;
i64       a[N], b[N], c[N];

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0, x, kk, maxi, kkk;
	bool flag = 0;
    scanf("%lld%lld", &n, &x);
	kk = n;
	maxi = x;
    getchar();
    for (i64 i = 0; i < n; i++) {
        scanf("%lld", a + i);
        b[i] = i;
		maxi = max(maxi, a[i]);
    }

	if (maxi == 0) {
		printf("%lld\n", n);
		return;
	}

	b[n] = n;

    i64 size = (log(maxi) / log(2));
    for (i64 i = size; i >= 0; i--) {
		kkk = t = 0;
		for (i64 j = 0; j < kk; j++) {
			for (i64 k = b[j]; k < b[j + 1]; k++) {
				if (a[k] & (1 << i)) t ^= 1;
			}
			if (t == 0) {
				c[++kkk] = b[j + 1];
			}
		}

		if (t == 1 && ((x & (1 << i)) == 0)) { // x该位为0， 而数组无法组合出0
			if (!flag) {
				printf("-1\n");
				return;
			}
			else {
				printf("%lld\n", kk);
				return;
			}
		}
		else if (t == 0 && (x & (1 << i))) { // x该位为1， 而数组可以组合出0
			if (flag) {
				printf("%lld\n", kk);
				return;
			}
			flag = 1;
			for (i64 j = 1; j <= kkk; j++) { // 拷贝
				b[j] = c[j];
			}
			ans = kk;
			kk = kkk;
		}
		else if ((x & (1 << i)) == 0) {
			if (flag) {
				printf("%lld\n", kk);
				return;
			}

			for (i64 j = 1; j <= kkk; j++) { // 拷贝
				b[j] = c[j];
			}
			
			kk = kkk;
		}
		else {
			if (flag) {
				printf("%lld\n", kk);
				return;
			}
		}
	}
	if (flag) 
    	printf("%lld\n", ans);
	else
    	printf("%lld\n", kk);

}

int main() {
    i64 _ = 1;
    scanf("%lld", &_);
    getchar();
    for (i64 __ = 0; __ < _; __++) { solve(); }
    system("pause");

    return 0;
}
