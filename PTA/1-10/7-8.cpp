#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);

    printf("Speed: %d - %s", n, n > 60 ? "Speeding" : "OK");
    //system("pause");
    return 0;
}