// https://codeforces.com/problemset/problem/816/B
#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
i64 a[N];
SI s;

inline i64 lower_bit(i64 x) {return (x) & (-x);}

int tree[N];
inline void insert(int i, int x = 1) {
    for (int pos = i; pos < N; pos += lower_bit(pos))
        tree[pos] += x;
}
inline int query(int n) {
    int ans = 0;
    for (int pos = n; pos; pos -= lower_bit(pos))
        ans += tree[pos];
    return ans;
}
inline int query(int a, int b) {
    return query(b) - query(a - 1);
}

class SegmentTree {
public:
    i64 n;
    vector<i64> arr, tag;
    SegmentTree() : n(0) {}
    SegmentTree(i64 n_, i64 v_ = 0) { //n_个常数v_
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
        function<void(i64, i64, i64)> build = [&] (i64 p, i64 l, i64 r) {
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
        arr[p] = min(arr[p << 1], arr[p << 1 | 1]);
    }
    void push(i64 p, i64 l, i64 r) {
        i64 m = (l + r) >> 1;
        arr[p << 1] += tag[p];
        tag[p << 1] += tag[p];
        arr[p << 1 | 1] += tag[p];
        tag[p << 1 | 1] += tag[p];
        tag[p] = 0;
    }
    void update(i64 p, i64 l, i64 r, i64 x, i64 y, i64 n) {
        if (l > y || r < x) return;
        if (l >= x && r <= y) {
            arr[p] += n;
            if (r != l) tag[p] += n;
        }
        else {
            i64 m = (l + r) >> 1;
            push(p, l, r);
            update(p << 1, l, m, x, y, n);
            update(p << 1 | 1, m + 1, r, x, y, n);
            pull(p);
        }
    }
    void update(i64 l, i64 r, i64 v) {
        update(1, 0, n - 1, l, r, v);
    }
    void travel(i64 p, i64 l, i64 r, i64 k) {
        if (arr[p] >= k) {
            for (i64 i = l; i <= r; i++) {
                insert(i);
            }
        }
        else if (r != l) {
            i64 m = (l + r) >> 1;
            push(p, l, r);
            travel(p << 1, l, m, k);
            travel(p << 1 | 1, m + 1, r, k);
        }
    }
    void travel(i64 k) {
        travel(1, 0, n - 1, k);
    }
};

void solve() {
    i64 n = 0, k = 0, q = 0, ans = 0, cnt = 0, l, r;
    scanf("%lld%lld%lld", &n, &k, &q); getchar();
    SegmentTree T(N);
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld", &l, &r);
        T.update(l, r, 1);
	}
    T.travel(k);
    for (i64 i = 0; i < q; i++) {
        scanf("%lld%lld", &l, &r);
        r = query(r); l = query(l - 1);
        printf("%lld\n", r - l);
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
