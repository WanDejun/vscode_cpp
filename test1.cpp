#include <stdio.h>
#include <windows.h>

int main() {
    char str[100];
    scanf("%s", str);
    char c = getchar();
    if (c == '\n' || c == '\0') printf("1\n");
    system("pause");
    return 0;
}