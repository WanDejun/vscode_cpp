// https://codeforces.com/problemset/problem/864/D#include <bits/stdc++.h>
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
i64 arr[N], cnt[N], val[N], kk;
bool flag[N];

void solve() {
    i64 n, m, t, ans = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", arr + i);
        cnt[arr[i]]++;
	}
    for (i64 i = 1 ; i <= n; i++) {
        if (!cnt[i]) val[kk++] = i;
    }
    printf("%lld\n", kk);
    for (i64 i = 0, j = 0; i < n; i++) {
        if (cnt[arr[i]] > 1) {
            if (!flag[arr[i]] && val[j] > arr[i]) {
                flag[arr[i]] = 1;
            }
            else {
                cnt[arr[i]]--;
                arr[i] = val[j++];
            }
        }
    }
	for (i64 i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }
    putchar('\n');
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
