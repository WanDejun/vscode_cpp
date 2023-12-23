#include <stdio.h>
// #include <Windows.h>
#define N 5000

int arr[N + 5];

void solve () {
    long long n, i, j, sum = 0, cnt = 0;
    scanf("%lld", &n);

    for (i = 0; i < n; i++) {
        scanf("%lld", arr + i);
    }

    for (i = 0, j = 0; j < n; j++) {
        sum += arr[j];
        while (sum > 7777) {
            sum -= arr[i];
            i++;
        }
        if (sum == 7777) cnt++;
    }
    printf("%lld\n", cnt);
}

int main() {
    int T, i;
    scanf("%d", &T);
    for (i = 0; i < T; i++) solve();

    // system("pause");
}
