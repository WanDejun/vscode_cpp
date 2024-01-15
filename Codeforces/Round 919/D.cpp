	#include <bits/stdc++.h>

	#define PII array<i64, 2>
	#define MII map<i64, i64>
	#define MSI map<string, i64>
	#define SI set<i64>
	#define VI vector<i64>
	#define i64 long long

	using namespace std;

	const i64 N = 2e4 + 5;
	const i64 MOD = 998244353;
	PII arr[N];
	i64 n;

	i64 cal(i64 t, __int128 cnt) {
		for (i64 i = n; i > 0; i--) {
			if (arr[i][0] == 1) {
				if (cnt == t) return arr[i][1];
				else cnt--;
			}
			else {
				cnt /= (arr[i][1] + 1);
				t = (t - 1) % cnt + 1;
			}
		}
		return -1;
	}

	void solve() {
		i64 m = 0, t = 0, ans = 0, q;
		__int128 cnt = 0;
		scanf("%lld%lld", &n, &q); getchar();
		for (i64 i = 1; i <= n; i++) {
			scanf("%lld%lld", &arr[i][0], &arr[i][1]);
			if (cnt <= 1e18) {
				if (arr[i][0] == 1) cnt++;
				else cnt *= (arr[i][1] + 1);
				m++;
			}
		}
		n = m;
		for (i64 i = 0; i < q; i++) {
			scanf("%lld", &t);
			printf("%lld ", cal(t, cnt));
		}
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
