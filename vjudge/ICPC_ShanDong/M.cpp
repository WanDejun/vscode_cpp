#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100000
struct Node {
    double x, y;
};
Node operator - (const Node a, const Node b) {
    return {a.x - b.x, a.y - b.y};
}
double cal(Node a, Node b, Node c) {
    b = b - a;
    c = c - a;
    return b.x * c.y - b.y * c.x;
}
int n, k;
Node s[MAX_N + 5];
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> s[i].x >> s[i].y;
    }
    double sum = 0, ans = 0;
    for(int i = 0, j = i + 1, z = i + k + 1; i < n; i++) {
        while((j - i + n) % n < k) {
            sum += cal(s[i], s[j], s[(j + 1) % n]) / 2;
            j = (j + 1) % n;
        }
        while(cal(s[i], s[j], s[z]) < cal(s[i], s[j], s[(z + 1) % n])) {
            z = (z + 1) % n;
        }
        ans = max(ans, sum + cal(s[i], s[j], s[z]) / 2);
        sum -= cal(s[i], s[i + 1], s[j]) / 2;
    }
    printf("%.10lf\n", ans);
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    system("pause");
}