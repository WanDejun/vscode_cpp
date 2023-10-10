#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    double a, b;
    scanf("%lf%lf", &a, &b);

    if (b > 40) b = 40 + (b - 40) * 1.5;

    printf("%.2f", (a >= 5 ? 50 : 30) * b);
    system("pause");
    return 0;
}