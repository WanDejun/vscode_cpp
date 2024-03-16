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
i64 a[N], b[N];

void solve() {
    i64 n = 0, k1 = 0, k2 = 0, ans1 = 0, ans2 = 0, r, c;
    set<i64> S;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld", &r, &c);
        if (r == 1) {
            if (c < 0) a[k1++] = c;
            else b[k2++] = c;
        }
        else {
            S.insert(c);
        }
	}

    if (k1 == 0) { 
        if (S.size() > 0 && *min_element(S.begin(), S.end()) <= 0) ans1++;
        else ans1 += 2;
    }
    else {
        for (i64 i = 0; i < k1; i++) {
            if (S.find(a[i] + 1) != S.end() || S.find(a[i]) != S.end() || S.find(a[i] - 1) != S.end()) { ans1--; break; }  
        }
        ans1++;
    }
    if (k2 == 0) {
        if (S.size() > 0 && *max_element(S.begin(), S.end()) >= 0) ans1++;
        else ans1 += 2;
    }
    else {
        for (i64 i = 0; i < k2; i++) {
            if (S.find(b[i] + 1) != S.end() || S.find(b[i]) != S.end() || S.find(b[i] - 1) != S.end()) { ans1--; break; }
        }
        ans1++;
    }

    S.insert(0);

    if (k1 == 0) { 
        if (S.size() > 0 && *min_element(S.begin(), S.end()) <= 0) ans2++;
        else ans2 += 2;
    }
    else {
        for (i64 i = 0; i < k1; i++) {
            if (S.find(a[i] + 1) != S.end() || S.find(a[i]) != S.end() || S.find(a[i] - 1) != S.end()) { ans2--; break; }  
        }
        ans2++;
    }
    if (k2 == 0) {
        if (S.size() > 0 && *max_element(S.begin(), S.end()) >= 0) ans2++;
        else ans2 += 2;
    }
    else {
        for (i64 i = 0; i < k2; i++) {
            if (S.find(b[i] + 1) != S.end() || S.find(b[i]) != S.end() || S.find(b[i] - 1) != S.end()) { ans2--; break; }
        }
        ans2++;
    }
	
	printf("%lld\n", min(ans1, ans2 + 1));
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
