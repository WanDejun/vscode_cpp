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
i64 a[N], b[N], m, n;
set<PII> S;

class line {
public:
	i64 k, m;
	line() {};
	line(i64 k, i64 m) : k(k), m(m) {}
};

i64 linesCnt;
line lines[10];

PII crossPoint(line l1, line l2) {
	if (l1.k == l2.k) {
		return {-1, -1};
	}
	i64 x =  -(l1.m - l2.m) / (l1.k - l2.k), y = (l1.k * l2.m - l2.k * l1.m) / (l1.k - l2.k);
	if (x > n || y > m || x < 1 || y < 1) return { -1, -1 };
	return {x, y};
}

void solve() {
    i64 t = 0, ansx, ansy, mini = LLONG_MAX;
	linesCnt = 0;
	S.clear();
	cin >> n >> m;

    cout << "? " << 1 << " " << 1 << endl; cout.flush();
	cin >> t;
	lines[linesCnt++] = line(-1, t + 1 + 1);

	cout << "? " << 1 << " " << m << endl; cout.flush();
	cin >> t;
	lines[linesCnt++] = line(1, m - t - 1);

	cout << "? " << n << " " << 1 << endl; cout.flush();
	cin >> t;
	lines[linesCnt++] = line(1, 1 + t - n);

	for (i64 i = 0; i < linesCnt; i++) {
		for (i64 j = i + 1; j < linesCnt; j++) {
			S.insert(crossPoint(lines[i], lines[j]));
		}
	}

	if (S.find({-1, -1}) != S.end())  {
		S.erase(S.find({-1, -1}));
	}
	cout << "? " << (*S.begin())[0] <<  " " << (*S.begin())[1] << endl; cout.flush();
	cin >> t;

	if (t != 0) {
		S.erase(S.begin());
	}
	cout << "! " << (*S.begin())[0] << " " << (*S.begin())[1] << endl;
}

int main() {
	i64 _ = 1;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
