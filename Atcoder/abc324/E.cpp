#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define FI first
#define SE second
#define i64 long long
#define i32 long

using namespace std;

const i64 N = 5e5 + 5;
const i64 MOD = 998244353;
i64 pre[N], back[N], cnt_p[N], cnt_b[N];
string x, s;
void f(i64 index) {
    cin >> x;
    i64 i, j;
    for (i = j = 0; i < s.length() && j < x.length(); j++) {
        if (s[i] == x[j]) i++;
    }
    pre[index] = i;
    for (i = s.length() - 1, j = x.length() - 1; i >=0 && j >= 0; j--) {
        if (s[i] == x[j]) i--;
    }
    back[index] = s.length() - i - 1;
}
void solve() {
    i64 n, ans = 0;
    scanf("%lld", &n); getchar();
    cin >> s;
    for (i64 i = 0; i < n; i++) {
        f(i);
    }
    for (i64 i = 0; i < n; i++) {
        cnt_p[pre[i]]++;
        cnt_b[back[i]]++;
    }
    for (i64 i = s.length() - 1; i >= 0; i--) {
        cnt_p[i] += cnt_p[i + 1];
        cnt_b[i] += cnt_b[i + 1];
    }
    for (i64 i = 0; i < n; i++) {
        ans += cnt_b[s.length() - pre[i]];
    }
    printf("%lld", ans);
}

signed main() {
    solve();

    //system("pause");
    return 0;
}
