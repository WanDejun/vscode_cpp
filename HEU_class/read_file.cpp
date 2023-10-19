#include <bits/stdc++.h>
using namespace std;

int main() {
    FILE* fp = fopen("./test.txt", "w");
    if (fp == NULL) return -1;

    char c = getchar();
    while (c != '\n') {
        fputc(c, fp);
        c = getchar();
    }
    fputc(c, fp);
    fclose(fp);
    return 0;
}