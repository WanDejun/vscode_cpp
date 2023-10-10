#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long
#define i32 long

using namespace std;

//i64 a[100005], b[100005], c[100005];

void solve() {
    i64 a, b;
    scanf("%lld%lld", &a, &b);
    map<i64, i64> m;
    a = (a % b) * 10;
    i64 i = 1;
    while (m.find(a) == m.end() && a != 0) {
        //printf("%d ", a);
        m.insert({a, i});
        i++;
        a = (a % b) * 10;
    }
    if (a == 0) printf("-1\n");
    else {
        printf("%lld %lld\n", m[a] - 1, i - m[a]);
    }
} 

signed main() {
    solve();

	system("pause");

	return 0;
}