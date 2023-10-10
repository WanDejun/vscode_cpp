#include <bits/stdc++.h>
#include <windows.h>

#define i64 long long
using namespace std;

// void qsort(vector<int>& nums, int st, int ed) {
// 	if (st >= ed) return;
// 	int l = st, r = ed, t = nums[l];
// 	while (l < r) {
// 		while (nums[r] >= t && r > l) r--;
// 		nums[l] = nums[r];
// 		while (nums[l] <= t && l < r) l++;
// 		nums[r] = nums[l];
// 	}	
// 	nums[l] = t;
// 	qsort(nums, st, l - 1);
// 	qsort(nums, l + 1, ed);
// }
void put(int n) {
	for (int i = 0; i < n; i++) {
		printf("%c", 219);
	}
	putchar('\n');
}
void bubble_sort(vector<int>& nums) {
	int temp, n = nums.size();
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

signed main() {
	system("chcp 437");
	const int n = 200000;
	i64 a = 1, b = 1, c = 2;
	for (i64 i = 0; i < n; i++) {
		a = b; b = c; c = a + b;
	}
	cout << c << " ";
	system("pause");
	return 0;
}