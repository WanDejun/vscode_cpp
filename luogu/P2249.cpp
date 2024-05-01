// #include <stdio.h>
// #include <stdlib.h>

// int a[1000001], b[100001];
// int bisearch(int x, int a[], int n) {
//     int left = 0, right = n - 1, k;
//     while (left < right) {
//         int mid = (left + right) / 2;
//         if (a[mid] >= x) right = mid;
//         else {
//             left = mid + 1;
//         }
//     }
//     if (a[left] == x) return left + 1;
//     else return -1;
// }
// int main(void) {
//     int n, m, ans;

//     scanf("%d %d", &n, &m);
//     for (int i = 0; i < n; i++) { scanf("%d", &a[i]); }
//     for (int i = 0; i < m; i++) {
//         scanf("%d", &b[i]);
//         printf("%d ", bisearch(b[i], a, n));
//     }
//     system("pause");
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const i64 N = 1e6 + 5;

i64 a[N];

int main(void) {
    i64 n, m, t;

    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < n; i++) { scanf("%lld", &a[i]); }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &t);
        i64 idx = lower_bound(a, a + n, t) - a;
        if (a[idx] != t) idx = -2;
        printf("%lld ", idx + 1);
    }
    system("pause");
    return 0;
}