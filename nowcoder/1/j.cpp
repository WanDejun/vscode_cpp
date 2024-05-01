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
char strs[10][N];
string strings[10];

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		for (i64 j = 0; ; j++) {
            strs[i][j] = getchar();
            if (strs[i][j] == '#') {
                strs[i][j] = '\0';
                break;
            }
            else if (strs[i][j] == '\n') {
                j--;
            }
        }
	}
    for (i64 i = 0; i < n; i++) {
        strings[i] = strs[i];
    }

    bool f = 0;
    for (i64 cnt = 0; cnt <= 10; cnt++) {
        f = 0;
        for (i64 i = 0; i < strings[0].length(); i++) {
            if (strings[0][i] == '*') {
                f = 1;
                t = strings[0][i + 1] - '0';
                strings[0] = strings[0].substr(0, i) + strings[t] + strings[0].substr(i + 2);
            }
        }
    }

    if (f = 0) printf("#");
	for (i64 i = 0; i < n; i++) {
        strings[i] = strs[i];
    }
	printf("%lld\n", ans);
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
