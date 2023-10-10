#include<bits/stdc++.h>
#define i64 long long
using namespace std;

template<class T>
void qsort(T& nums, i64 st, i64 ed) {
	if (st >= ed) return;
	i64 l = st, r = ed;
    i64 t = nums[l];
	while (l < r) {
		while (nums[r] >= t && r > l) r--;
		nums[l] = nums[r];
		while (nums[l] <= t && l < r) l++;
		nums[r] = nums[l];
	}
	nums[l] = t;
	qsort(nums, st, l - 1);
	qsort(nums, l + 1, ed);
}

signed main() {
	vector<int> nums{50,37,75,34,13,74,85,42,72,93};
	qsort(nums, 0, nums.size() - 1);
	for (auto n : nums) cout << n << ' ';
	system("pause");
	return 0;
}