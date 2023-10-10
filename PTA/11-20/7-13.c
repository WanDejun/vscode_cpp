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

const i64 N = 100 + 5;
const i64 MOD = 998244353;
char str[3][N];
bool flag[3][N];

void solve() {
    int n = 0;
    scanf("%lld", &n); getchar();
    int mini = INT_MAX;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            str[i][j] = getchar() - 'a';
        }
        getchar();
    }
    for (int i = 0; i < n; i++) {
        int a = str[0][i], b = str[1][i], c = str[2][i];
        if (f[1][a] && f[2][a]) mini = min(i, mini);
        if (f[0][b] && f[2][b]) mini = min(i, mini);        
        if (f[1][c] && f[0][c]) mini = min(i, mini);
        if (b == c) 
    }
    printf("%d\n", -1);
}

signed main() {
    solve();

    system("pause");
    return 0;
}