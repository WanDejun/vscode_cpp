// https://atcoder.jp/contests/abc309/tasks/abc309_f
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
i64 arr[N], n;
array<array<i64, 3>, N> a;
inline i64 lower_bit(i64 x) {return (x) & (-x);}
void init() { //离散化
    i64 i, j;
    for (i = 0; i < n; i++) {
        arr[i] = a[i][1];
    }
    sort(arr, arr + n);
    for (i = 1, j = 1; j < n; j++) {
        if (arr[j] != arr[j - 1]) arr[i++] = arr[j];
    }
    for (j = 0; j < n; j++) {
        a[j][1] = lower_bound(arr, arr + i, a[j][1]) - arr + 1;
    }


    for (i = 0; i < n; i++) {
        arr[i] = a[i][2];
    }
    sort(arr, arr + n);
    for (i = 1, j = 1; j < n; j++) {
        if (arr[j] != arr[j - 1]) arr[i++] = arr[j];
    }
    for (j = 0; j < n; j++) {
        a[j][2] = lower_bound(arr, arr + i, a[j][2]) - arr + 1;
    }
}

i64 query(i64 x) {
    i64 ans = LLONG_MAX, t;
    while (x) {
        ans = min(ans, arr[x]);
        t = lower_bit(x);
        x ^= t;
    }
    return ans;
}

void insert(i64 x, i64 val) {
    i64 t;
    for (i64 i = x; i <= n; i += lower_bit(i)) {
        arr[i] = min(arr[i], val);
    }
}

void solve() {
    i64 m, t;
    //bool ans = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &(a[i][0]), &(a[i][1]), &(a[i][2]));
        sort(a[i].begin(), a[i].end(), [](i64 a, i64 b){return a > b;});
	}
    sort(a.begin(), a.begin() + n, [](array<i64, 3>& x, array<i64, 3>& y) {return x[0] < y[0];});
    init();
    for (i64 i = 0; i <= n; i++) {
        arr[i] = LLONG_MAX;
    }
    for (i64 i = 0, j = 0; j < n; j++) {
        if (a[i][0] != a[j][0]) {
            for (i64 k = i; k < j; k++) {
                insert(a[k][1], a[k][2]);
            }
            i = j;
        }
        if (query(a[j][1] - 1) < a[j][2]) {printf("Yes\n"); return;}
    }
	
	printf("No\n");
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
