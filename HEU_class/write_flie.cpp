#include <bits/stdc++.h>
using namespace std;

int main() {
    FILE* fp = fopen("./test.txt", "r");
    if (fp == NULL) return -1;

    char c = fgetc(fp);
    while (c != '\n') {
        putchar(c);
        c = fgetc(fp);
    }
    putchar(c);
    system("pause");
    return 0;
}