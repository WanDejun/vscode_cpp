#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long

using namespace std;
const i64 N = 1e5 + 5;
i64 a[N];

void solve() {
    i64 n, m, ans = LLONG_MAX, t;
    scanf("%lld%lld", &n, &m); getchar();
    (n *= 6) %= 10;
    for (i64 i = 0; i < m ;i++) {
        (n *= n) %= 10;
    }
    cout << n << endl;
} 

signed main() {
    solve();

	system("pause");

	return 0;
}