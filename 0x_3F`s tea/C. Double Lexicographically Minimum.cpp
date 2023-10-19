// https://codeforces.com/problemset/problem/1799/C 2023-10-18
#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 1e5 + 5;
const i64 MOD = 998244353;
char a[N];
i64 cnt[26];

void solve() {
    i64 n, m, ans = 0, c_char = 0;
    for (i64 i = 0; i < 26; i++) cnt[i] = 0;
    //scanf("%lld", &n); getchar();
    char c = getchar();
	for (n = 0; c != '\n'; n++) {
		cnt[c - 'a']++;
        c = getchar();
	}
    for(i64 i = 0; i < 26; i++) if (cnt[i]) c_char++;
    i64 l = 0, r = n - 1;
    char t = -1;
    for (i64 i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        c_char--;
        if (cnt[i] % 2) {
            for (i64 j = 0; j < (cnt[i] >> 1); j++) {
                a[l++] = a[r--] = 'a' + i;
            }
            if (c_char == 1) {
                a[n / 2] = 'a'+ i;
                for (i++; i < 26; i++) {
                    if (cnt[i]) {
                        for (i64 j = l; j <= r; j++) if (j != static_cast<i64>(n / 2)) {
                            a[j] = i + 'a';
                        }
                    }
                }
            }
            else {
                a[r--] = i +'a';
                for (i++; i < 26 ;i++) {
                    for (i64 j = 0; j < cnt[i]; j++) {
                        a[l++] = i + 'a';
                    }
                }
            }
            break;
        }
        for (i64 j = 0; j < (cnt[i] >> 1); j++) {
            a[l++] = a[r--] = 'a' + i;
        }
    }
	
    for (i64 i = 0; i < n; i++) putchar(a[i]);
    putchar('\n');
}

int main() {
	i64 _;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
