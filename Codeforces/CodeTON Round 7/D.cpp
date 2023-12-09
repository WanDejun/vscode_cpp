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
    i64 n = 0, m = 0, t = 0, ans = 0, tot = 0, loc_l = 0, loc_r = 0, ll = 0, lr = 0, rl = 0, rr = 0, q;
    bool flag = 1;
    scanf("%lld%lld", &n, &q); getchar();
    a[0] = a[n + 1] = 0;
	for (i64 i = 1; i <= n; i++) {
		scanf("%lld", a + i);
        if (a[i] == 1) {
            if (loc_l == 0) {
                loc_l = i;
                ll = tot;
            }
            loc_r = i;
            rl = tot;
        }
        tot += a[i];
	}
    lr = tot - 1 - ll;
    rr = tot - 1 - rl;
	
    if (loc_r == 0) {flag = 0; loc_l = n + 1;}

    i64 s, v, opcode;
    
    for (i64 k = 0; k < q; k++) {
        scanf("%lld", &opcode);
        if (opcode == 1) {
            scanf("%lld", &s);
            if (s % 2 == tot % 2 && s <= tot) printf("Yes\n");
            else if (flag) printf("%s\n", max({ll, lr, rl, rr}) + 1 >= s ? "Yes" : "No");
            else printf("No\n");
        }
        else {
            scanf("%lld%lld", &s, &v);
            if (a[s] == v) continue;

            a[s] = v;
            if (v == 1) tot--;
            else tot++;

            if (s < loc_l) { // 在loc_l左侧
                if (v == 1) {ll--;flag = 1;}
                else ll++;

                for (; loc_l > s; loc_l--) {
                    ll -= a[loc_l - 1];
                    lr += a[loc_l];
                }
            }
            else if (s > loc_l) { // 在loc_l右侧
                if (v == 1) lr--;
                else lr++;
            }
            else { //loc_l被修改
                do {
                    ll += a[loc_l];
                    lr -= a[loc_l + 1];
                    loc_l++;
                } while (a[loc_l] == 2 && loc_l <= n);
                if (loc_l == n + 1) flag = 0;
            }
            //////
            if (s > loc_r) { // 在loc_l右侧
                if (v == 1) {rr--;flag = 1;}
                else rr++;

                for (; loc_r < s; loc_r++) {
                    rl += a[loc_r];
                    rr -= a[loc_r + 1];
                }
            }
            else if (s < loc_r) { // 在loc_r左侧 
                if (v == 1) rl--;
                else rl++;
            }
            else { //loc_r被修改
                do {
                    rr += a[loc_r];
                    rl -= a[loc_r - 1];
                    loc_r--;
                } while (a[loc_r] == 2 && loc_r > 0);
                if (loc_r == 0) flag = 0;
            }
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
