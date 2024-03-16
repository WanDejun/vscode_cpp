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
i64 nxt[N], b[N], ans;

#include <iostream>
#include <string>
using namespace std;

void kmp_nxt(string& s, i64 st) {
	int k = st, i, n = s.length(), t;
	nxt[st] = st - 1; 
	for (i = st + 1; i < n; i++) {
		nxt[i] = k;
		if (s[i] == s[k] && s[i] != '?') nxt[i] = nxt[k]; 
		while (k != st - 1 && (s[i] != s[k] && s[i] != '?' && s[k] != '?')) k = nxt[k];

        t = 1;
        if ((i - st + 1) <= (k - st + 1) * 2) {
            if ((i - st + 1) % 2 == 0) {
                for (i64 p = st, q = st + (i - st + 1) / 2; q <= i; p++, q++) {
                    if (s[p] != s[q] && s[p] != '?' && s[q] != '?') {t = 0; break;}
                }
                if (t) ans = max(ans, (i - st + 1));
            }
        }

		k++;
	}
} 

void solve() {
    ans = 0;
    string s;
    cin >> s;
	
    for (i64 i = 0; i < s.length() - 1; i++) {
        kmp_nxt(s, i);
    }

	printf("%lld\n", ans);
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
