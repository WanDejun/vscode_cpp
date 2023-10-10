#include <stdio.h>

int main() {
    int a[3], i;
    for (i = 0; i < 3; i++) a[i] = getchar() - '0';
    for (i = 2; i >= 0; i--) 
        if (a[i]) {putchar(a[i] + '0');break;}
    for (i--; i >= 0; i--) putchar(a[i] + '0');
    getchar(); getchar();
    return 0;
}