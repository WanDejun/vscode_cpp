#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n, x, y;
void solve() {
    cin >> n >> x >> y;
    cout << "Yes" << endl << n - 1 << endl;
    int up = x;
    int down = x;
    int l = y;
    int r = y;
    int cnt = 1;
    while(cnt < n) {
        if(up > 1 && r < n) {
            up--;
            r++;
            cout << up << " " << r << " " << cnt << " " << -cnt << endl;
        }
        else if(up > 1 && l > 1) {
            up--;
            l--;
            cout << up << " " << l << " " << cnt << " " << cnt << endl;
        }
        else if(l > 1 && down < n) {
            l--;
            down++;
            cout << down << " " << l << " " << -cnt << " " << cnt << endl;
        }
        else {
            r++;
            down++;
            cout << down << " " << r << " " << -cnt << " " << -cnt << endl;
        }
        cnt++;
    }
}
signed main() {
    solve();
    system("pause");
}