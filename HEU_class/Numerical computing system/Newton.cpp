#include <iostream>
#include <windows.h>
using namespace std;

const int N = 10;

double px[N], py[N], mx[N][N];
int n;

void New_input() {
    printf("input the number of point:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("input the %d point(x then y):", i + 1);
        scanf("%lf%lf", px + i, py + i);
        mx[0][i] = py[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            mx[i][j] = (mx[i - 1][j] - mx[i - 1][j + 1]) / (px[j] - px[j + i]);
            printf("%lf ", mx[i][j]);
        }
        putchar('\n');
    }
}

double New_cal_sub(double x) {
    double ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans *= (x - px[i]);
        ans += mx[i][0];
    }
    return ans;
}

void New_cal() {
    double t;
    char c;
    New_input();
    while (1) {
        printf("input the x that you want to calculate:");
        scanf("%lf", &t);
        t = New_cal_sub(t);
        cout << t << endl;
        printf("continue cal (y/n): ");
        c = getchar();
        while (c == '\n') c = getchar();
        if (c == 'n') break;
    }
}
int main() {
    New_cal();
    system("pause");
    return 0;
}