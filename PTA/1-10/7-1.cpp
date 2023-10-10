#include <stdio.h>

int main() {
    int cm, inch, foot;
    scanf("%d", &cm);
    cm *= 12;
    inch = cm / 30.48;
    foot = inch / 12;
    inch %= 12;
    printf("%d %d", foot, inch);
    //getchar(); getchar();
    return 0;
}