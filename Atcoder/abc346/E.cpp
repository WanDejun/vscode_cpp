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
i64 a[N][3], kk;
PII output_queue[N];

void solve() {
    i64 n, m, t, ans = 0, H, W;
    scanf("%lld%lld%lld", &H, &W, &n); getchar();
    map<i64, i64> cnt;
    set<i64> S_column, S_row;
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
	}

    for (i64 i = n - 1; i >= 0; i--) {
        if (a[i][0] == 1) {
            if (S_row.find(a[i][1]) == S_row.end() && (W - S_column.size() > 0)) {
                S_row.insert(a[i][1]);
                cnt[a[i][2]] += (W - S_column.size());
            }
        }
        else {
            if (S_column.find(a[i][1]) == S_column.end() && (H - S_row.size() > 0)) {
                S_column.insert(a[i][1]);
                cnt[a[i][2]] += (H - S_row.size());
            }
        }
    }
	
    i64 sum = 0;
    for (auto& it : cnt) {
        sum += it.second;
    }
    if (W * H - sum > 0)
        cnt[0] += (W * H - sum);

    for (auto& it : cnt) {
        output_queue[kk][0] = it.first;
        output_queue[kk++][1] = it.second;
    }

    sort(output_queue, output_queue + kk, [](PII& a, PII& b){return a[0] < b[0];});

    printf("%lld\n", kk);
    for (i64 i = 0; i < kk; i++) {
	    printf("%lld %lld\n", output_queue[i][0], output_queue[i][1]);
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
