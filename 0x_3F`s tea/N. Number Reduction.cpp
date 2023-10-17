        //https://codeforces.com/problemset/problem/1765/N  2023-10-17
        #include <bits/stdc++.h>

        #define PII array<i64, 2>
        #define MII multimap<i64, i64>
        #define MSI multimap<string, i64>
        #define SI multiset<i64>
        #define VI vector<i64>
        #define i64 long long
        #define rep(i,a,b) for (i64 i = a; i < b; i++)

        using namespace std;

        const i64 N = 5e5 + 5;
        const i64 MOD = 998244353;
        char str[N];
        bool flags[N];
        //i64 c0[N];

        void print(i64 st, i64 n) {
            for (i64 i = st; i < n; i++) {
                if (!flags[i]) printf("%c", str[i] + '0');
            }
            putchar('\n');
        }

        void solve() {
            i64 n, k, cnt = 0, st = 0, mini = 11, loc;
            char c = getchar();
            for (n = 0; c != '\n' && c != '\0'; n++) {
                str[n] = c - '0';
                c = getchar();
                flags[n] = 0;
            }
            scanf("%lld", &k); getchar();
            for (i64 i = 0; i <= k; i++) if (str[i] > 0 && str[i] < mini) {
                mini = str[i]; st = i;
            }
            cnt += st;

            for (i64 i = st + 1; i < n && cnt < k; i++) {
                if (str[i] < str[i - 1]) {
                    if (str[i] == 0) {
                        for (i64 j = i - 1; j > st; j--) if (!flags[j]) {
                            if (str[j] == 0) break;
                            flags[j] = 1; cnt++;
                            if (cnt == k) break;
                        }
                    }
                    else {
                        for (i64 j = i - 1; j >= st; j--) if (!flags[j]) {
                            if (str[j] <= str[i]) {
                                break;
                            }
                            flags[j] = 1; cnt++;
                            if (j == st) st = i;
                            if (cnt == k) break;
                        }
                    }
                }
            }
            if (cnt < k) {
                for (i64 i = n - 1; i >= 0 && cnt < k; i--) if (!flags[i]) {
                    flags[i] = 1;
                    cnt++;
                }
            }
            
            print(st, n);
        }

        int main() {
            i64 _;
            scanf("%lld", &_); getchar();
            for (i64 __ = 0; __ < _; __++) {
                solve();
            }
            //system("pause");

            return 0;
        }
