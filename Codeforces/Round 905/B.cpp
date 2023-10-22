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
i64 cnt[26];

void solve() {
    i64 n, m, t, k, c = 0;
    char ch;
    scanf("%lld%lld", &n, &k); getchar();
    for (i64 i = 0; i < 26; i++) cnt[i] = 0;
	for (i64 i = 0; i < n; i++) {
		ch = getchar();
        cnt[ch - 'a']++;
	} getchar();
    for (i64 i = 0; i < 26; i++) {
        if (cnt[i] % 2) c++;
    }
    if (c <= k + 1) cout << "Yes" << endl;
    else cout << "No" << endl;
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
