//https://codeforces.com/problemset/problem/1106/D
#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 1e5 + 5;
const i64 MOD = 998244353;
bool flag[N];

class cmp {
public:
    operator()(i64 a, i64 b) {return a > b;}
};

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0, u, v;
    scanf("%lld%lld", &n, &m); getchar();
    vector<vector<i64>> mx(n);
	for (i64 i = 0; i < m; i++) {
		scanf("%lld%lld", &u, &v);
        u--; v--;
        mx[u].push_back(v);
        mx[v].push_back(u);
	}
    priority_queue<i64, vector<i64>, cmp> q;
    q.push(0); flag[0] = 1;
    while (!q.empty()) {
        u = q.top(); q.pop();
        printf("%lld ", u + 1);
        for (i64 v : mx[u]) if (!flag[v]) {
            flag[v] = 1;
            q.push(v);
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
