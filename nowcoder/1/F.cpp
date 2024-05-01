#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e2 + 5;
const i64 MOD = 998244353;
string types[3] = {"Camel", "Pascal", "Snake"};
string type;
string strs[N], str_ans[N];

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
    scanf("%lld", &n);
    cin >> type;
	for (i64 i = 0; i < n; i++) {
		cin >> strs[i];
	}

    if (type == types[0]) { // Camel
        for (i64 i = 0; i < n; i++) {
            str_ans[i] += (strs[i][0] | (1 << 5));
            for (i64 j = 1; j < strs[i].length(); j++) {
                if (strs[i][j] == '_') {
                    strs[i][j + 1] &= ~(1 << 5);
                    continue;
                }
                str_ans[i] += strs[i][j];
            }
        }
    }
    else if (type == types[1]) { // Pascal
        for (i64 i = 0; i < n; i++) {
            str_ans[i] += (strs[i][0] & ~(1 << 5));
            for (i64 j = 1; j < strs[i].length(); j++) {
                if (strs[i][j] == '_') {
                    strs[i][j + 1] &= ~(1 << 5);
                    continue;
                }
                str_ans[i] += strs[i][j];
            }
        }
    }
    else { // Snake
        for (i64 i = 0; i < n; i++) {
            str_ans[i] += strs[i][0] | (1 << 5);
            for (i64 j = 1; j < strs[i].length(); j++) {
                if ((strs[i][j] & (1 << 5)) == 0 && strs[i][j] != '_') {
                    str_ans[i] += '_';
                    strs[i][j] |= (1 << 5);
                }
                str_ans[i] += strs[i][j];
            }
        }
    }

    for (i64 i = 0; i < n; i++) {
        cout << str_ans[i] << endl;
    }
}

int main() {
	i64 _ = 1;
	//scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
