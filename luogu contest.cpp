#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long
#define i32 long

using namespace std;

char num[17];
i64 a[1000005];
int num[10] = {2, 7, 11, 14, 22, 77, 3, 7, 21, 49};

void solve() {
	i64 n, k = -1, kk = 0, cnt = 0, x, y;
    scanf("%lld", &n); getchar();
    char t = getchar();
    set<int> flag;
    bool OK = 0;
    while (t != '\0' && t != '\n') {
        if (kk < 17) num[kk++] = t;
        t = getchar();
    }

    if (kk < 17) {
        k = 0;
        for (int i = 0; i < kk; i++) {k *= 10; k += num[i] - '0';}
    }
    if ((n == 1 && n < k) || k == -1) {printf("No\n"); return;}
    for (int i = 0; i < 10; i++) flag[i] = 0;
    for (i64 i = 0; i < n; i++) {
        scanf("%lld", a + i);
        if (!OK) {
            if (a[i] % 154 == 0 || a[i] % 147 == 0) OK = 1;
            for (int j = 0; j < 6; j++) {
                if (a[i] % num[j] == 0) {
                    flag.insert(num[j]);
                    if (flag.find(154 / num[j]) != flag.end()) {cnt++;if (cnt == 2) OK = 1;}
                }
            }
            for (int j = 6; j < 10; j++) {
                if (a[i] % num[j] == 0) {
                    flag.insert(num[j]);
                    if (flag.find(147 / num[j]) != flag.end()){cnt++;if (cnt == 2) OK = 1;}
                }
            }
        }
    }
    if (OK) printf("OK\n");
    else if (cnt == 1) 


    printf("No\n");
}

int main() {
    i64 _;
    scanf("%lld", &_);

    for (i64 __ = 0; __ < _; __++) {
        solve();
    }
	system("pause");

	return 0;
}