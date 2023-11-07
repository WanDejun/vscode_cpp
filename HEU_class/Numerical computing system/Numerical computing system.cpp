#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
using namespace std;

const int N = 10;
const double eps = 1e-6;

double a[N], px[N], py[N], mx[N][N];
int n;

//Dichotomy
double f(double x) {
    return pow(x, 3) - 0.2 * pow(x, 2) - 0.2 * x - 1.2;
}

double bi_search(double l, double r) {
    double mid, t;
    bool flag = 0;
    if (f(r) * f(l) > 0) {printf("The interval does not conform to the zero theorem!\n"); return -1;}
    if (f(r) > 0) flag = 1;
    while (r - l > eps) {
        mid = (l + r) / 2;
        t = f(mid);
        if (abs(t) < eps) return mid;
        if ((t > 0 && flag) || t < 0 && !flag) r = mid;
        else l = mid;
    }
    return mid;
}

void bi_cal() {
    double l, r;
    char c;
    while (1) {
        printf("input two end point of interval:");
        scanf("%lf%lf", &l, &r);
        printf("%.6lf\n", bi_search(l, r));

        printf("continue dichotomy?(y/n):");
        c = getchar();
        while (c == '\n') c = getchar();
        getchar();
        if (c == 'n') return;
    }
}
//Newton Interpolation algorithm
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
//Lagrange Interpolation algorithm
void Lag_input() {
    printf("input n:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", px + i, py + i);
    }
}

void Lag_cal() {
    double x, ans = 0;
    Lag_input();
    printf("input x:");
    scanf("%lf", &x);
    for (int i = 0; i < n; i++) {
        double t = py[i];
        for (int j = 0; j < n; j++) if (j != i) {
            t *= ((x - px[j]) / (px[i] - px[j]));
        }
        ans += t;
    }
    printf("f(x) = %lf\n", ans);
}
//Qin Jiuzhao algorithm
void Qin_input() {
    printf("input n:");
    scanf("%d", &n);
    printf("input arg form x^0 to x^n");
    for (int i = 0; i <= n; i++) {
        scanf("%lf", a + i);
    }
}

void Qin_cal() {
    double ans = 0, x;
    Qin_input();
    printf("input x:");
    scanf("%lf", &x);
    for (int i = n; i >=0; i--) {
        ans = ans * x + a[i];
    }
    printf("ans = %lf\n", ans);
}

int main() {
    int op;
    while (1) {
        printf("-------------------------------------------------------\n");
        printf("1:Newton Interpolation algorithm\n");
        printf("2:Lagrange Interpolation algorithm\n");
        printf("3:Dichotomy\n");
        printf("4:Qin Jiuzhao algorithm\n");
        printf("0:quit\n");
        printf("input the opcode:");
        scanf("%d", &op);
        switch (op) {
        case 1:
            New_cal();
            break;
        case 2:
            Lag_cal();
            break;
        case 3:
            bi_cal();
            break;
        case 4:
            Qin_cal();
            break;
        case 0:
            goto TAG;
        default:
            break;
        }
    }
TAG:
    system("pause");
    return 0;
}