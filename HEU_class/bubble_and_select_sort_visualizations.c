#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define N 20
#define MAXN 50

void putblocks(int n) {
    for (int i = 0; i < n; i++) { printf("%c", 219); }
    for (int i = 0; i < MAXN - n; i++) { putchar(' '); }
}
void put(int nums1[], int nums2[], int k) {
    for (int i = 0; i < N; i++) {
        putblocks(nums1[i]);
        printf("%s", i == k ? "<-     " : "       ");
        putblocks(nums2[i]);
        printf("%s\n", i == k ? "<-     " : "       ");
    }
}
void sort(int nums1[], int nums2[]) {
    int temp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = N - 1; j > i; j--) {  // 冒泡排序
            if (nums1[j] < nums1[j - 1]) {
                temp = nums1[j];
                nums1[j] = nums1[j - 1];
                nums1[j - 1] = temp;
            }
        }
        int loc = i;
        for (int j = i + 1; j < N; j++) {  // 选择排序
            if (nums2[j] < nums2[loc]) { loc = j; }
        }
        temp = nums2[i];
        nums2[i] = nums2[loc];
        nums2[loc] = temp;

        put(nums1, nums2, i);

        Sleep(1000);
        system("cls");
    }
}

int main() {
    int nums1[N], nums2[N];

    system("chcp 437");
    system("cls");
    srand(time(0));

    for (int i = 0; i < N; i++) { nums1[i] = nums2[i] = rand() % MAXN + 1; }
    sort(nums1, nums2);

    // for (int i = 0; i < N; i++) printf("%lld ", nums1[i]); putchar('\n');
    // for (int i = 0; i < N; i++) printf("%lld ", nums2[i]); putchar('\n');
    system("pause");
    return 0;
}