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
i64 out[N], kk;
string x, s;
bool check_n() {
    i64 n = x.size();
    for (i64 i = 0, j = 0; i < n; i++, j++) {
        if (x[i] != s[j]) {
            if (i != j) return false;
            else j--;
        } 
    }
    return true;
}
bool check_z() {
    bool flag = 0;
    i64 n = x.size();
    for (i64 i = 0; i < n; i++) {
        if (x[i] != s[i]) {
            if (flag) return false;
            else flag = 1;
        } 
    }
    return true;
}
bool check_p() {
    i64 n = x.size();
    for (i64 i = 0, j = 0; i < n; i++, j++) {
        if (x[i] != s[j]) {
            if (i != j) return false;
            else i--;
        } 
    }
    return true;
}
void solve() {
    i64 n;
    scanf("%lld", &n); getchar();
    cin >> x;
    for (i64 i = 0; i < n; i++) {
        cin >> s;
        if (s.length() == x.length()) {if (check_z()) out[kk++] = i + 1;}
        else {
            if (s.length() == x.length() - 1) {if (check_n()) out[kk++] = i + 1;}
            else if (s.length() == x.length() + 1) {if (check_p()) out[kk++] = i + 1;}
        }
    }
    printf("%lld\n", kk);
    for (i64 i = 0; i < kk; i++) {
        printf("%lld ", out[i]);
    }
}

signed main() {
    solve();

    //system("pause");
    return 0;
}
