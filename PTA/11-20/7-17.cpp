#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, u, d, v;
    cin >> n >> u >> d;
    v = u - d;
    if (n > u) cout << ((n - u + v - 1) / v) * 2 + 1 << endl;
    else cout << (n == 0 ? 0 : 1) << endl;

    system("pause");
    return 0;
}