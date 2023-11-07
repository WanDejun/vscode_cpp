#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;

const int N = 10;

double px[N], py[N];
int n;

void Lag_input() {
    printf("input n:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", px + i, py + i);
    }
}

double Lag_cal(double x) {
    double ans = 0;
    for (int i = 0; i < n; i++) {
        double t = py[i];
        for (int j = 0; j < n; j++) if (j != i) {
            t *= ((x - px[j]) / (px[i] - px[j]));
        }
        ans += t;
    }
    return ans;
}

int main() {
    double t;
    Lag_input();
    scanf("%lf", &t);
    t = Lag_cal(t);
    cout << t << endl;
    system("pause");
    return 0;
}
/*
5
0.4 0.410705
0.55 0.57815
0.65 0.69675
0.8 0.88811
0.9 1.02652
0.596
*/