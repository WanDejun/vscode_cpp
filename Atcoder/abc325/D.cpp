//错误解法：贪心
#include <bits/stdc++.h>

#define PII array<long long, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
PII a[N];
class cmp{
public:
	bool operator()(PII& a, PII& b) {return a[1] > b[1];}
};
void solve() {
    long long n, m, t, ans = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld", &(a[i][0]), &(a[i][1]));
		a[i][1] += a[i][0];
	}
	sort(a, a + n, [](PII& a, PII& b){return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];});
	t = 1;
	i64 i = 0;
	priority_queue <PII, vector<PII>, cmp> q;
	while (1) {
		if (q.empty()) {
			if (i == n) break;
			else {
				t = a[i][0];
				q.push(a[i]); i++;
				while (i < n && a[i][0] == t) {
					q.push(a[i]);
					i++;
				}
			}
		}
		PII temp = q.top(); q.pop();
		if (temp[1] >= t) {ans++;t = max(t, temp[0]) + 1;}
		while (i < n && a[i][0] == t) {
			q.push(a[i]);
			i++;
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
