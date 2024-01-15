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
i64 a[N], b[N];

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
    i64 XX, YY, x1, x2, y1, y2;
    scanf("%lld%lld%lld%lld%lld%lld", &XX, &YY, &x1, &y1, &x2, &y2); getchar();
    t = (x2 - x1) / 2;
    if (x2 <= x1) printf("Draw\n");
	else if ((x2 - x1) % 2) {
        if (y2 == y1) {
            printf("Alice\n");
        }
        else if (y2 > y1) {
            if (y1 + t + 1 >= min(y2 + t, YY))  printf("Alice\n");
            else printf("Draw\n");
        }
        else {
            if (y1 - t - 1 <= max(y2 - t, 1ll)) printf("Alice\n");
            else printf("Draw\n");
        }
    }
    else {
        if (y2 == y1) {
            printf("Bob\n");
        }
        else if (y1 > y2) {
            if (y2 + t >= min(y1 + t, YY))  printf("Bob\n");
            else printf("Draw\n");
        }
        else {
            if (y2 - t <= max(y1 - t, 1ll)) printf("Bob\n");
            else printf("Draw\n");
        }
    }
}

int main() {
	i64 _ = 1;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
