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
i64 C[N], S[N];
class node {
public:
	i64 fa;
	i64 tot = -1;
	vector<i64> child;
};
vector<i64> G[N];
node arr[N];

void get_sum(i64 idx) {
	i64 sum = 0, tot = 0;
	for (i64 i = 0; i < arr[idx].child.size(); i++) {
		if (arr[arr[idx].child[i]].tot == -1) {
			get_sum(arr[idx].child[i]);
		}
		tot += arr[arr[idx].child[i]].tot;
		sum += (S[arr[idx].child[i]] + arr[arr[idx].child[i]].tot);
	}
	arr[idx].tot = tot + C[idx];
	S[idx] = sum;
}

void bfs() {
	queue<i64> q;
	q.push(0);
	arr[0].fa = -1;

	while (!q.empty()) {
		for (i64 n : G[q.front()]) if (n != arr[q.front()].fa) {
			arr[n].fa = q.front();
			arr[q.front()].child.push_back(n);
			q.push(n);
		}
		q.pop();
	}
}

void solve() {
    i64 n, m, t, ans = 0, a, b, mini = LLONG_MAX;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n - 1; i++) {
		scanf("%lld%lld", &a, &b);
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (i64 i = 0; i < n; i++) {
		scanf("%lld", C + i);
	}

	bfs();
	get_sum(0);
	mini = S[0];

	queue<i64> q;
	for (i64 n : arr[0].child) q.push(n);
	while(!q.empty()) {
		i64 idx = q.front();
		q.pop();
		S[idx] = S[arr[idx].fa] + (arr[0].tot - 2 * arr[idx].tot);
		mini = min(mini, S[idx]);
		for (i64 i : arr[idx].child) {
			q.push(i);
		}
	}
	
	printf("%lld\n", mini);
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
