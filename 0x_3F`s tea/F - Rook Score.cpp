//https://atcoder.jp/contests/abc298/tasks/abc298_f
#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
map<i64, i64> mapx, mapy;
map<pair<i64, i64>, i64> point;
pair<i64,i64> sx[N];

void solve() {
    i64 n, m, t, ans = 0;
    i64 x, y, v, nx = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &x, &y, &v);
        mapx[x] += v; mapy[y] += v;
        point.insert({{x, y}, v});
	}
	for (auto &it : mapx) {
        sx[nx].first = it.first;
        sx[nx].second = it.second;
        nx++;
    }
    sort(sx, sx + nx, [](pair<i64, i64>& a, pair<i64, i64>& b) {return a.second > b.second;});
    for (auto &it : mapy) {
        for (i64 i = 0; i < nx; i++) {
            if (point.find({sx[i].first, it.first}) != point.end()) {
                ans = max(ans, it.second + sx[i].second - point[{sx[i].first, it.first}]);
            }
            else {
                ans = max(ans, it.second + sx[i].second);
                break;
            }
        }
    }
	printf("%lld\n", ans);
}

int main() {
	i64 _ = 1;
	//scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
