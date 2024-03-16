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
char a[N];
const string str1 = "DFS", str2 = "dfs";
void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
    i64 state1 = 0, state2 = 0;

    scanf("%lld", &n); getchar();
	scanf("%s", a);
    for (i64 i = 0; i < n; i++) {
        if (a[i] == str1[state1]) state1++;
        if (a[i] == str2[state2]) state2++;
    }
	
	printf("%d %d\n", state1 == 3 ? 1 : 0, state2 == 3 ? 1 : 0);
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
