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

void solve() {
    string a, b;
    cin >> a >> b;
	a = a.substr(2);
	i64 n = (stoi(a) + 1) / 2, cnt_R = 0, cnt_P = 0;
	for (i64 i = 0; i < b.length(); i++) {
		if (b[i] == 'R') {
			cnt_R++;
			if (cnt_R == n) {
				printf("kou!\n%lld\n", i + 1);
				return;
			}
		}
		else {
			cnt_P++;
			if (cnt_P == n) {
				printf("yukari!\n%lld\n", i + 1);
				return;
			}
		}
	}
	
	printf("to be continued.\n%lld\n", b.length());
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
