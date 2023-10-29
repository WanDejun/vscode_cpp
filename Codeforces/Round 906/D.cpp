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
i64 a[N], b[N];

class cmp{
public:
	bool operator() (PII& a, PII& b) {
		return a[0] > b[0];
	}
};

void solve() {
    i64 n, m, t = -1, ans = 0, sum = 0, c;
    scanf("%lld%lld", &n, &c); getchar();
	priority_queue<PII, vector<PII>, cmp> q;
	for (i64 i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	sum += a[1]; 

	for (i64 i = 2; i <= n; i++) {
		q.push({i * c - a[i], i});
	}
	PII p;
	while (!q.empty()) {
		p[0] = q.top()[0]; p[1] = q.top()[1]; q.pop();
		if (p[0] > sum) {printf("No\n"); return;}
		sum += a[p[1]];
	}
	
	printf("Yes\n");
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
