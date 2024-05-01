#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> s;
vector<int> ss;
int n;
vector<pair<int, int>> g;
bool check(int x) {
    s.clear();
    ss.clear();
    for(int i = 0; i < g.size(); i++) {
        auto t = g[i];
        if(t.first < x) {
            ss.push_back(t.second);
        }
        else {
            s.push_back(t.first + t.second);
        }
    }
    if(s.size() < ss.size()) return false;
    sort(s.begin(), s.end(), greater<int>());
    sort(ss.begin(), ss.end(), greater<int>());
    for(int i = 0; i < ss.size(); i++) {
        if(s[i] - ss[i] < x) return false;
    }
    return true;
}
void solve() {
    cin >> n;
    g.clear();
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        g.push_back({x, y});
    }
    int l = 1, r = 1e9;
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}