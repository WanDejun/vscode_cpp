#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define MAX_N 1000006
const int MAX_M = 50;
const int n=19;
int fa[MAX_M * MAX_M];
list<int> s[MAX_M * MAX_M];
int sum[MAX_M * MAX_M];
int board[MAX_M][MAX_M];
int dd(int x,int y){
	return x * MAX_M + y;
}
pair<int,int> change(int n){
	return {n / MAX_M, n % MAX_M};
}
int dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0, 0};
bool isout(int x,int y){
	return x < 1 || y < 1 || x > n || y > n;
}
int find(int x){
	return fa[x] = fa[x] == x ? x : find(fa[x]);
}
void merge(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y)return;
	if(s[x].size() < s[y].size()) swap(x,y);
	fa[y] = x;
	sum[x] += sum[y];
	s[x].splice(s[x].end(), s[y]);
}
int cal(int x,int y){
	int p = find(dd(x,y));
	if(sum[p]) return 0;
	int siz = s[p].size();
	for(auto v : s[p]){
		auto [X, Y] = change(v);
		board[X][Y] = 0;
		for(int j = 0; j < 4; j++)
			sum[find(dd(X + dx[j], Y + dy[j]))]++;
	}
	return siz;
}
void solve() {
    int m;
	cin >> m;
	for(int i = 1, opt = 1; i <= m; i++, opt ^= 3){
		int x, y;
		cin >> x >> y;
		board[x][y] = opt;
		sum[dd(x,y)] = 4 - (x==1) - (y==1) - (x==n) - (y==n);
		fa[dd(x,y)] = dd(x,y);
		s[dd(x,y)] = {dd(x,y)};
		for(int j = 0; j < 4; j++){
			int X = x + dx[j], Y = y + dy[j];
			if(isout(X,Y)) continue;
			if(board[X][Y]){
				sum[dd(x,y)]--;
				sum[find(dd(X,Y))]--;
			}
		}
		for(int j = 0; j < 4; j++){
			int X = x + dx[j], Y = y + dy[j];
			if(isout(X,Y)) continue;
			if(board[X][Y] == board[x][y])
				merge(dd(X,Y),dd(x,y));
		}
		int A=0,B=0;
		for(int j = 0; j < 4; j++){
			int X = x + dx[j], Y = y+dy[j];
			if(isout(X,Y) || !board[X][Y]) continue;
			if(board[X][Y] != board[x][y]) A += cal(X,Y);
		}
		for(int j = 0; j < 4; j++){
			int X = x + dx[j], Y = y + dy[j];
			if(isout(X,Y) || !board[X][Y]) continue;
			B += cal(X,Y);
		}
		if(!isout(x, y) && board[x][y]) {
			B += cal(x, y);
		}
		if(opt == 1) swap(A,B);
		cout << A << ' ' << B << endl;
        //cout << endl;
	}
}
signed main(){
	solve();
    //system("pause");
}