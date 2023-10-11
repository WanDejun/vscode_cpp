#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long
#define i32 long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
i64 L[N], R[N], X[N], col[N];
bool flag[N];
char str[N];
bool f = 0;

class SegmentTree {
public:
    int n;
    vector<i64> arr, tag;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, i64 v_ = 0) { //n_个常数v_
        init(n_, v_);
    }
    SegmentTree(vector<i64> init_) { //数组初始化
        init(init_);
    }
    void init(i64 n_, i64 v_ = 0) {
        init(vector<i64>(n_, v_));
    }
    void init(vector<i64> init_) {
        n = init_.size();
        arr = vector<i64> (n << 2);
        tag = vector<i64> (n << 2);
        function<void(int, int, int)> build = [&] (i64 p, i64 l, i64 r) {
            if (l == r) {
                arr[p] = init_[l];
                return;
            }
            i64 m = (l + r) >> 1;
            build(p << 1, l, m);
            build(p << 1 | 1, m + 1, r);
            pull(p);
        };
        build(1, 0, n - 1);
    }
    void pull(i64 p) { //down to up
        arr[p] = arr[p << 1] & arr[p << 1 | 1];
    }
    void push(i64 p, i64 l, i64 r) {
        i64 m = (l + r) >> 1;
        arr[p << 1] += tag[p] * (m - l + 1);
        tag[p << 1] += tag[p];
        arr[p << 1 | 1] += tag[p] * (r - m);
        tag[p << 1 | 1] += tag[p];
        tag[p] = 0;
    }
    void update(i64 p, i64 l, i64 r, i64 x, i64 y, i64 n) {
        if (l > y || r < x) return;
        if (l >= x && r <= y) {
            arr[p] += (r - l + 1) * n;
            if (r != l) tag[p] += n;
        }
        else {
            i64 m = (l + r) >> 1;
            //push(p, l, r);
            update(p << 1, l, m, x, y, n);
            update(p << 1 | 1, m + 1, r, x, y, n);
            pull(p);
        }
    }
    void update(i64 l, i64 r, i64 n) {
        update(1, 0, n - 1, l, r, n);
    }
    i64 query(i64 p, i64 l, i64 r, i64 x, i64 y) {
        if (l > y || r < x) return LLONG_MAX;
        if (l >= x && r <= y) return arr[p];
        else {
            i64 m = (l + r) >> 1;
            push(p, l, r);
            return query(p << 1, l, m, x, y) & query(p << 1 | 1, m + 1, r, x, y);
        }
    }
    i64 query(i64 l, i64 r) {
        return query(1, 0, n - 1, l, r);
    }
};

i64 bisearch(i64 k, i64 st, SegmentTree& T) {
    i64 mid, val, l = st, r = T.n - 1;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        val = T.query(st, mid);
        if (val >= k) l = mid;
        else r = mid - 1;
    }
    return l;
}

void solve() {
    i64 n, q, t, l, r, k;
    scanf("%lld", &n); getchar();
    vector<i64> arr(n);
    for (i64 i = 0 ; i < n; i++) {
        scanf("%lld", &(arr[i]));
    } getchar();
    SegmentTree T(arr);
    scanf("%lld", &q);
    for (i64 i = 0; i < q; i++) {
        scanf("%lld%lld", &l, &k);
        l--;
        if (k > arr[l]) printf("-1 ");
        else printf("%lld ",bisearch(k, l, T) + 1);
    }
    putchar('\n');
}

int main() {
	i64 _;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
