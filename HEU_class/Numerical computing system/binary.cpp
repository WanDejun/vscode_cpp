#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
using namespace std;

const int N = 10;
const double eps = 1e-6;

double f(double x) {
    return pow(x, 3) - 0.2 * pow(x, 2) - 0.2 * x - 1.2;
}

double bi_search(double l, double r) {
    double mid, t;
    bool flag = 0;
    if (f(r) * f(l) > 0) {system("pause"); exit(1);}
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

int main() {
    double l, r;
    scanf("%lf%lf", &l, &r);
    printf("%.12lf", bi_search(l, r));

    system("pause");
    return 0;
}