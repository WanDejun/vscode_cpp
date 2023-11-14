#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
char a[N];
char b[N];
i64 kk;
stack<char> st;

inline void pop_all() {
    stack<char> t;
    char c;
    while (!st.empty()) {
        c = st.top(); st.pop();
        switch (c) {
        case 1:
            t.push('C');
            break;
        case 2:
            t.push('B');
            t.push('C');
            break;
        default:
            t.push(c);
            break;
        }
    }
    while (!t.empty()) {
        b[kk++] = t.top();
        t.pop();
    }
}

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
    //scanf("%lld", &n); getchar();
    char c = getchar();
	while (c != '\n') {
        a[n++] = c;
        c = getchar();
    }
    for (i64 i = n - 1; i >= 0; i--) {
        if (a[i] == 'C') {
            st.push(1);
        }
        else if (a[i] == 'B') {
            if (!st.empty() && st.top() == 1) {
                st.pop(); st.push(2);
            }
            else {
                pop_all();
                b[kk++] = 'B';
            }
        }
        else {
            if (!st.empty() && st.top() == 2) {
                st.pop();
            }
            else {
                pop_all();
                b[kk++] = 'A';
            }
        }
    }
    pop_all();
    for (i64 i = kk - 1; i >= 0; i--) {
        putchar(b[i]);
    }
    putchar('\n');
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
