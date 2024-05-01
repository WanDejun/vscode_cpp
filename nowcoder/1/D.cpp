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
char str[N], ans[N];

inline bool is_split(const char c) {
    if ((c <= 'z' && c >= 'a') || c <= 'Z' && c >= 'A') {
        return false;
    }
    return true;
}

void solve() {
    i64 n = 0, m = 0, t = 0, cnt = 0;
    i64 i = 0, j = 0;
    for (i = 0; ; i++) {
        str[i] = getchar();
        if (str[i] == '\n' || str[i] == '\r' || str[i] == '\0') {
            str[i] = '\0';
            break;
        }
    }
	for (i = 0, j = 0; j <= strlen(str); j++) {
		if (is_split(str[j])) {
            if (j - i > 0) ans[n++] = (j - i) % 10;
            i = j + 1;
        } 
	}

    for (i = 0; i < n; i++) {
	    printf("%d", ans[i]);
    }
    printf("\n");
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
