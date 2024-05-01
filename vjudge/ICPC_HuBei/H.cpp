#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pii pair<i64, i64>

#ifdef __DEBUG__
#    define N (static_cast<LL>(1e4 + 5))
#else
#    define N (static_cast<LL>(1e6 + 5))
#endif
using namespace std;
LL n, m, k, num, ans;
LL all[1005][1005];
struct node {
    LL x;
    LL y;
    LL num;
} nums[20];
LL cal(LL x, LL y) {
    LL sum = 0;
    if (all[x - 1][y] > 0) sum++;
    if (all[x + 1][y] > 0) sum++;
    if (all[x][y] > 0) sum++;
    if (all[x][y - 1] > 0) sum++;
    if (all[x][y + 1] > 0) sum++;
    return sum;
}
LL maxxxxxxxxxxxxxxxxxx(LL x, LL y) {
    LL maxx = 0;
    maxx = max(all[x - 1][y], maxx);
    maxx = max(all[x + 1][y], maxx);
    maxx = max(all[x][y - 1], maxx);
    maxx = max(all[x][y + 1], maxx);
    maxx = max(all[x][y], maxx);
    return maxx;
}
void pppp(LL x, LL y) {
    if (all[x][y] > 0) all[x][y]--;
    if (all[x - 1][y] > 0) all[x - 1][y]--;
    if (all[x + 1][y] > 0) all[x + 1][y]--;
    if (all[x][y + 1] > 0) all[x][y + 1]--;
    if (all[x][y - 1] > 0) all[x][y - 1]--;
}
void solve() {
    scanf("%lld %lld %lld", &n, &m, &k);
    LL x, y, sum = 0, maxi, cnt_x, cnt_y;
    for (int i = 0; i < k; i++) {
        scanf("%lld %lld %lld", &x, &y, &num);
        nums[i].x = x;
        nums[i].y = y;
        nums[i].num = num;
        all[x][y] = num;
        sum += num;
    }
    while (sum) {
        maxi = 0;
        for (int i = 0; i < k; i++) {
            x = nums[i].x;
            y = nums[i].y;
            if (nums[i].num == 0) continue;
            if (cal(x, y) > maxi) {
                maxi = cal(x, y);
                cnt_x = x;
                cnt_y = y;
            }
            if (x > 1 && cal(x - 1, y) > maxi) {
                maxi = cal(x - 1, y);
                cnt_x = x - 1;
                cnt_y = y;
            }
            if (cal(x + 1, y) > maxi) {
                maxi = cal(x + 1, y);
                cnt_x = x + 1;
                cnt_y = y;
            }
            if (y > 1 && cal(x, y - 1) > maxi) {
                maxi = cal(x, y - 1);
                cnt_x = x;
                cnt_y = y - 1;
            }
            if (cal(x, y + 1) > maxi) {
                maxi = cal(x, y + 1);
                cnt_x = x;
                cnt_y = y + 1;
            }
        }
        ans++;
        sum -= maxi;
        pppp(cnt_x, cnt_y);
    }
    printf("%lld", ans);
}
int main() {
    LL _ = 1;
    // scanf("%lld", &_); getchar();
    for (LL __ = 0; __ < _; __++) { solve(); }
    system("pause");
    return 0;
}