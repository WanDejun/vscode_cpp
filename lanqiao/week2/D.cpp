#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 1e5 + 5;
const i64 MOD = 998244353;
vector<i64> nxt[N];
PII info[N];
class cmp{
public:
    bool operator () (i64 a, i64 b){
        return info[a][1] > info[b][1];
    }
};
void solve() {
    i64 n, k, t, ans = 0, s;
    scanf("%lld%lld", &n, &s); getchar();
    for (i64 i = 1; i <= n; i++) {  
        scanf("%lld%lld%lld", &t, &info[i][0], &info[i][1]);
        nxt[t].push_back(i);
    }
    priority_queue<i64, vector<i64>, cmp> q;
    q.push(1);
    while (!q.empty()) {
        t = q.top(); q.pop();
        if (s < info[t][1]) break;
        s += info[t][0];
        ans++;
        for (i64& v : nxt[t]) {
            q.push(v);
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
