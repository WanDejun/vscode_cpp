#include <bits/stdc++.h>

#define pii array<i64, 2>
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
i64  a[N];

void solve() {
    i64 n, x, y;
    string id, id1, id2;
    double mini = LLONG_MAX, maxi = -1;
    scanf("%lld", &n); getchar();
    for (i64 i = 0; i < n; i++) {
        cin >> id;
        scanf("%lld%lld", &x, &y);
        double t = sqrt(x * x + y * y);
        if (t < mini) { id1 = id; mini = t; }
        if (t > maxi) { id2 = id; maxi = t; }
    }

    cout << id1 << " " << id2 << endl;
}
signed main() {
    solve();

    system("pause");
    return 0;
}
