#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void put(int n) {
	for (int i = 0; i < n; i++) {
		printf("%c", 219);
	}
	putchar('\n');
}
void bubble_sort(int* nums, int n) {
	int temp;
	bool flag;
	for (int i = 0; i < n; i++) {
		flag = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
				flag = 1;
			}
		}
		for (int j = 0; j < n; j++) {
			put(nums[j]);
		}
		Sleep(1000);
		system("cls");
		if (!flag) return;
	}
}

int main() {
	int nums[N];

    system("chcp 437");
	srand(time(0));

	for (int i = 0; i < N; i++) {
		nums[i] = rand() % 100 + 1;
	}
	bubble_sort(nums, N);

	system("pause");
	return 0;
}