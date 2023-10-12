#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long
#define i32 long

using namespace std;

const i64 N = 1e4 + 5;
const i64 MOD = 998244353;
i64 a[N], kk, cnt[N], nums[N];

bool check(i64 n) {
    for (i64 i = 2; i <= sqrt(n + 1); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
void tab() {
    for (i64 i = 2; i < 1e4 + 5; i++) {
        if (check(i)) a[kk++] = i;
    }
}

void solve() {
    i64 n, m, c, t, ans = 0;
    scanf("%lld", &n); getchar();
    for (i64 i = 0; i < kk; i++) {
        cnt[i] = 0;
    }
    bool f = 1;
    for (i64 i = 0; i < n; i++) {
        scanf("%lld", nums + i);
        if (i > 0 && nums[i] != nums[i - 1]) f = 0; 
    }
    if (f) {printf("Yes\n"); return;}
	for (i64 i = 0; i < n; i++) {
        t = nums[i];
        for (i64 j = 0; j < kk && t != 1; j++) {
            while (t % a[j] == 0) {
                cnt[j]++;
                t /= a[j];
            }
        }
        if (i == 0) m = t;
        if (m != t) {printf("No\n"); return;}
    }
    for (i64 i = 0; i < kk; i++) {
        if (cnt[i] && cnt[i] % n) {printf("No\n"); return;}
    }
	printf("Yes\n");
}

int main() {
	i64 _;
	scanf("%lld", &_); getchar();
    tab();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
