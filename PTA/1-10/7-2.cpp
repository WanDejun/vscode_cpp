#include <stdio.h>

int main() {
    int now_h, now_m, m, h;
    bool flag = 1;
    scanf("%d%d", &now_m, &m);
    if (m < 0) {flag = 0; m = -m;}
    now_h = now_m / 100;
    now_m %= 100;
    if (flag) {
        now_m += m;
        now_h += (now_m / 60);
        now_m %= 60;
        now_h %= 24;
    }
    else {
        now_m -= m;
        if (now_m < 0) {
            now_m = -now_m;
            now_h -= (now_m / 60);
            now_m %= 60;
            now_m = -now_m;
            if (now_m != 0) {now_h -= 1; now_m += 60;}
            now_h %= 24; if (now_h < 0) now_h += 24;
        }
    }
    printf("%d%d", now_h, now_m);
    if (now_m == 0) putchar('0');
    getchar(); getchar();
    return 0;
}