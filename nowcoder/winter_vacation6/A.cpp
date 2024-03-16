#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N], kk;

bool is_Prime(i64 n) {
	for (i64 i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false; 
	}
	return true;
}

void pre_process() {
	for (i64 i = 2; i < 35; i++) {
		if (is_Prime(i)) {
			a[kk++] = i;
		}
	}
}

void solve() {
    i64 t = 0, ans = 0, cnt = 0, l, r;
	pre_process();
    scanf("%lld%lld", &l, &r); getchar();
	for (i64 n = l; n <= r; n++) {
		t = n;
		cnt = 0;
		for (i64 i = 0; i < kk; i++) {
			if (a[i] > t) break;
			if (t % a[i] == 0) {
				t /= a[i];
				cnt++;
				if (cnt == 3) {
					if (t == 1) {printf("%lld\n", n); return;}
				}
			}
		}
	}
	
	printf("-1\n");
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
