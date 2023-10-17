#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define FI first
#define SE second
#define i64 long long

using namespace std;

const i64 N = 1e5 + 5;
const i64 MOD = 998244353;
i64 a[N];

void solve() {
    i64 n, ans = 0, x = -1, y = -1, c1, c2, c3;
    //scanf("%lld", &n); getchar();
    bool flag = 0;
    char c = getchar();
    i64 i = 0;
    while (c != '\n' && c != '\0') {
        switch (c)
        {
        case 'P':
            if (x != -1) flag = 1;
            x = i;
            break;
        case 'T':
            if (y != -1) flag = 1;
            y = i;
            break;
        case 'A':
            break;
        default:
            flag = 1;
            break;
        }
        i++;
        c = getchar();
    }
    c1 = x; c2 = y - x - 1; c3 = i - y - 1;
    //cout << c1 << c2 << c3 << endl;
    if (y - x < 2) flag = 1;
    if (c3 != c1 * c2) flag = 1;
    printf("%s\n", flag ? "NO" : "YES");
}
signed main() {
    i64 _;
    scanf("%lld", &_); getchar();
    for (i64 __ = 0; __ < _; __++) {
        solve();
    }

    system("pause");
    return 0;
}
