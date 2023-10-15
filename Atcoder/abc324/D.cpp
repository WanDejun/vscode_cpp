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

const i64 N = 1e6;
const i64 MOD = 998244353;
i64 cnt1[10], cnt2[10];

bool check(i64 n) {
    //for (i64 i = 0; i < 9; i++) cnt2[i] = 0;
    while (n) {
        cnt2[n % 10]++;
        n /= 10;
    }
    bool f = 1;
    for (i64 i = 1; i < 10; i++) {
        if (cnt1[i] != cnt2[i]) f = 0;
        cnt2[i] = 0;
    }
    cnt2[0] = 0;
    return f;
}

void solve() {
    i64 n, ans = 0;
    string s;
    scanf("%lld", &n); getchar();
    cin >> s;
    for (i64 i = 0; i < s.length(); i++) {
        cnt1[s[i] - '0']++;
        cnt2[s[i] - '0']++;
    }
    i64 maxi = 0;
    for (i64 i = 9; i >= 0; i--) {
        while (cnt2[i]) {maxi = maxi * 10 + i;cnt2[i]--;}
    }
    maxi = sqrt(maxi + 1);
    for (i64 i = 0; i <= maxi; i++) {
        if (check(pow(i, 2))) ans++;
    }
    cout << ans << endl;
}

signed main() {
    solve();

    //system("pause");
    return 0;
}
