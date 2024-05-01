#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long
#define ll long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
bool flag = 0;
int a,b;
ll count_black;
void dfs(ll dep,ll sum_red,ll sum_black) {
    if(dep == 3) {
        if(sum_red == a && sum_black == b) {
            flag = 1;
        }
        return ;
    }
    for(int i = 1;i <= 6;i++) {
        if(i == 1 || i == 4) {
            dfs(dep + 1,sum_red + i,sum_black);
        }
        else {
            dfs(dep + 1,sum_red,sum_black + i);
        }
    }
    return ;
}
void solve() {
    cin >> a >> b;
    //flag = 0;
    dfs(0,0,0);
    if(flag) printf("Yes");
    else printf("No");
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
/*
10 
4 5
3 0
8 0
12 0
3 5
6 3
4 2

*/
