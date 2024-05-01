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
i64 a[N], b[N];

void solve() {
	set<string> S;
	string s;
    i64 n, m, t, ans = 0;
	cin >> s;

	for (i64 i = 0; i < s.length(); i++) {
		for (i64 j = i; j < s.length(); j++) {
			S.insert(s.substr(i, j - i + 1));
		}
	}
	
	printf("%lld\n", S.size());
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
