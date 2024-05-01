#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 1e6 + 5;
const i64 MOD = 998244353;
i64 a[N], cnts[N], id[N], idx[N], output[N];

void solve() {
    i64 n = 0, m = 0, t1 = 0, t2 = 0, ans = 0, cnt = 0, k = 0;
    for (i64 i = 0; i < N; i++) {
        a[i] = -1;
    }

    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld %lld", &t1, &t2);
        a[t1] = t2;
        a[t2] = t1;
	}

    scanf("%lld", &m);
    for (i64 i = 1; i <= m; i++) {
        scanf("%lld", &t1);
        id[i] = t1;
        idx[t1] = i;
    }

    for (i64 i = 1; i <= m; i++) {
        cnts[i] += cnt;
        if (a[id[i]] != -1 && idx[a[id[i]]] != 0) {
            if (idx[a[id[i]]] == i + 1) {
                if(i > 0) cnts[i - 1]++;
                cnts[i + 2]++;
            }
            else if (idx[a[id[i]]] > i) {
                cnt++;
            }
            else if (idx[a[id[i]]] < i - 1) {
                cnt--;
            }
        }
    }

    ans = *max_element(cnts + 1, cnts + m + 1);
    for (i64 i = 1; i <= m; i++) {
        if (ans == cnts[i] && (a[id[i]] == -1 || idx[a[id[i]]] == 0))
            output[k++] = id[i];
    }

    sort(output, output + k);
    for (i64 i = 0; i < k - 1; i++) {
        printf("%lld ", output[i]);
    }
	
	printf("%lld", output[k - 1]);
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
