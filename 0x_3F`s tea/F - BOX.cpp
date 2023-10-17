//https://atcoder.jp/contests/abc279/tasks/abc279_f
#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define FI first
#define SE second
#define i64 long long

using namespace std;

const i64 N = 3e5 + 5;
const i64 MOD = 998244353;
i64 root[N], Tree[2 * N], box[2 * N];
i64 find(i64 u) {
    if (Tree[u] == u) return u;
    Tree[u] = find(Tree[u]);
    return Tree[u];
}
void merge(i64 u, i64 v) {
    Tree[find(v)] = find(u);
}


void solve() {
    i64 n, q, ans = 0;
    scanf("%lld%lld", &n, &q); getchar();
    for (i64 i = 1; i <= (n + q); i++) {
        Tree[i] = i;
        box[i] = i;
    }
    for (i64 i = 1; i <= n; i++) {
        root[i] = i;
    }
    i64 opcode, x, y, k = n;
    for (i64 i = 0; i < q; i++) {
        scanf("%lld", &opcode);
        switch (opcode) {
        case 1:
            scanf("%lld%lld", &x, &y);
            if (root[y] != -1) {
                if (root[x] == -1) {
                    root[x] = root[y];
                    box[root[x]] = x;
                }
                else merge(root[x], root[y]);
            } 
            root[y] = -1;
            break;
        case 2:
            scanf("%lld", &x);
            if (root[x] == -1) {
                root[x] = ++k;
                box[k] = x;
            }
            else { 
                Tree[++k] = root[x];
            }
            break;
        case 3:
            scanf("%lld", &x);
            printf("%lld\n", box[find(x)]);
            break;
        }
    }
}
signed main() {
    solve();

    system("pause");
    return 0;
}
