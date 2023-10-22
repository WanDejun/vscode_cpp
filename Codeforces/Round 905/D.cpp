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
map<i64, i64> lazy_max, lazy_min;
priority_queue<i64, vector<i64>, less<i64>> maxq;
priority_queue<i64, vector<i64>, greater<i64>> minq;

void solve() {
    i64 n, m, t, k, ans = 0, l, r, maxl = -1, minr = LLONG_MAX;
    char op;
    scanf("%lld", &n); getchar();
    for (i64 i = 0; i < n; i++) {
        op = getchar();
        scanf("%lld%lld", &l, &r); getchar();
        if (op == '+') {
            maxq.push(l);
            minq.push(r);
            maxl = maxq.top();
            minr = minq.top();
            printf("%s\n", minr < maxl ? "Yes" : "No");
        }
        else {
            lazy_max[l]++;
            lazy_min[r]++;
            while (lazy_max.find(maxq.top()) != lazy_max.end() && lazy_max[maxq.top()] != 0) {
                lazy_max[maxq.top()]--;
                maxq.pop();
            }
            maxl = maxq.top();
            while (lazy_min.find(minq.top()) != lazy_min.end() && lazy_min[minq.top()] != 0) {
                lazy_min[minq.top()]--;
                minq.pop();
            }
            minr = minq.top();
            printf("%s\n", minr < maxl ? "Yes" : "No");
        }
    }
    
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
