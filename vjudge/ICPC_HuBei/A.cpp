#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define pii pair<i64, i64>

#ifdef __DEBUG__
    #define N      (static_cast<LL>(1e4 + 5))
#else 
    #define N      (static_cast<LL>(1e6 + 5)) 
#endif
using namespace std;
LL x,y,a,b;
LL gcd(LL a,LL b) {
    return b>0 ? gcd(b,a%b):a;
}
void solve(){
    scanf("%lld %lld",&x,&y);
    LL k = gcd(x,y);
    LL cnt = x * y / (k * k);
    printf("1 %lld\n",cnt);
}
int main()
{            
    LL _ = 1;
    scanf("%lld", &_); getchar();
    for(LL __ = 0; __ < _; __++) {
        solve();
    }
    system("pause");
    return 0;
}