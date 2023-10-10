#include <stdio.h>
#include <stdlib.h>

int main() {
    double f1, f2;
    int i;
    char c;
    scanf("%lf%d", &f1, &i); getchar();
    c = getchar(); getchar();
    scanf("%lf", &f2);
    printf("%c %d %.2f %.2f", c, i, f1, f2);
    system("pause");
    return 0;
}