#include <bits/stdc++.h>

#define i64 long long
using namespace std;
i64 a[] = {1, 2, 3};
signed main() {
	int loc = find(a, a + 2, 2) - a;
	cout << loc << endl;
	system("pause");
	return 0;
}