#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long
#define i32 long

using namespace std;

const i64 N = 1e2;
const i64 MOD = 998244353;
bool a[N][N], b[N], c[N];

void solve() {
    i64 n, m;
    string s1, s2;
    scanf("%lld%lld", &n, &m); getchar();
	cin >> s1 >> s2;
    //cout << s1 << endl << s2 << endl;
    int ans = 0;
    while (s1.length() < 3 * max(m, n)) {
        if (s1.find(s2, 0) < 200) {
            cout << ans << endl;
            return;
        }
        ans++;
        s1 += s1;
    }
	printf("-1\n");
}

int main() {
	i64 _;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
