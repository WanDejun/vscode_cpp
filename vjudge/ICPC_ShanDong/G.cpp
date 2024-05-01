#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long
using namespace std;

typedef long long ll;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N];
ll num;
void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
    unordered_map<ll,vector<ll> > all;
    scanf("%lld", &n); getchar();
	for (i64 i = 1; i <= n; i++) {
		scanf("%lld", &num);
        all[num - i + 1].push_back(num);
	}
	for(auto x : all) {
        for(int i = x.second.size() - 1;i >=1 ;i--) {
            if(x.second[i] + x.second[i - 1] > 0) {
                ans += x.second[i] + x.second[i - 1];
                i--;
            }
        }
    }
	printf("%lld\n", ans);
}

int main() {
	i64 _ = 1;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
