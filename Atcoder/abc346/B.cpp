#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e2 + 5;
const i64 MOD = 998244353;
i64 cnt_w[N], cnt_b[N];

const string str = "wbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbw";

void solve() {
    i64 n = 48, m, t, ans = 0, w, b;
    scanf("%lld%lld", &w, &b); getchar();
	
	i64 t1 = w / 7, t2 = b / 5;
	while (w + b >= 48) {
		w -= 7;
		b -= 5;
	} 
	if (w < 0 || b < 0) {
		printf("No");
		return;
	}

	for (i64 i = 0; i < n; i++) {
		cnt_w[i + 1] = cnt_w[i];
		if (str[i] == 'w') {
			cnt_w[i + 1]++;
		}
	}

	for (i64 i = 0; i + w + b < n; i++) {
		if ((cnt_w[i + w + b] - cnt_w[i] == w)) {
			printf("Yes");
			return;
		}
	}

	printf("No");
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
