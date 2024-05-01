#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e1 + 5;
const i64 MOD = 998244353;
i64       a[N], b[N];
string    strs[N];

bool compare(string& s, int idx) {
    int n = 0, m = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (strs[idx][i] == s[j]) {
                n++;
                break;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        if (s[i] == strs[idx][i]) m++;
    }
    return (n == a[idx] && m == b[idx]);
}

void solve() {
    i64    n = 0, m = 0, t = 0, cnt = 0;
    string s = "xxx";
    vector<string> ans;
    for (i64 i = 0; i < 5; i++) {
        cin >> strs[i];
        scanf("%lld%lld", a + i, b + i);
        getchar();
    }

    for (char c0 = 'A'; c0 <= 'Z'; c0++) {
        s[0] = c0;
        for (char c1 = 'A'; c1 <= 'Z'; c1++) {
            s[1] = c1;
            for (char c2 = 'A'; c2 <= 'Z'; c2++) {
                s[2] = c2;
                bool flag = 1;
                for (i64 i = 0; i < 5 && flag; i++) {
                    flag &= compare(s, i);
                }
                if (flag) {
                    ans.push_back(s);
                }
            }
        }
    }

    printf("%lld\n", ans.size());
    for (i64 i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    i64 _ = 1;
    // scanf("%lld", &_); getchar();
    for (i64 __ = 0; __ < _; __++) { solve(); }
    system("pause");

    return 0;
}
