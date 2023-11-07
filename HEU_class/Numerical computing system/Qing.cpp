#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;

const int N = 10;

double a[N];
int n;

void qin_input() {
    printf("input n:");
    scanf("%d", &n);
    printf("input arg form x^0 to x^n");
    for (int i = 0; i <= n; i++) {
        scanf("%lf", a + i);
    }
}
double qin_cal() {
    double ans = 0, x;
    printf("input x:");
    scanf("%lf", &x);
    for (int i = n; i >=0; i--) {
        ans = ans * x + a[i];
    }
    return ans;
}

int main() {
    qin_input();
    cout << qin_cal() << endl;
    system("pause");
    return 0;
}