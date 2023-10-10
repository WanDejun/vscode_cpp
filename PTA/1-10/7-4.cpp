#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%d", &n);
    a = n / 16;
    b = n % 16;
    if (a) printf("%d", a);
    printf("%d", b);
    getchar(); getchar();
    return 0;
}