#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int a = 0, b = 0;
    char s[10];
    int n, i;
    bool f = 0;
    scanf("%s", s);
    n = strlen(s);
    for (i = 0; i < n && s[i] != ':'; i++) {
        a = a * 10 + s[i] - '0';
    }
    //printf("%d\n", i);
    for (i++; i < n; i++) {
        b = b * 10 + s[i] - '0';
    }
    if (a > 12) {f = 1; a -= 12;}
    else if (a == 12) f = 1;
    printf("%d:%d %s", a, b, f ? "PM" : "AM");
    system("pause");
    return 0;
}