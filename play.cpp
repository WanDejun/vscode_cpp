#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,n,d;
    scanf("%d %d",&n,&d);
    struct a{
       double kucun;
       double zongjia;
       double junjia;

    };
	a yuebin [50];
    for(i=0;i<n;i++){
         scanf("%d",&(yuebin[i].kucun));
    }
    for(i=0;i<n;i++){
        scanf("%d",&(yuebin[i].zongjia));
    }
    for(i=0;i<n;i++){
        yuebin[i].junjia=yuebin[i].zongjia*1.0/yuebin[i].kucun;
    }
    /*for(i=0;i<n;i++){
        for(j=i+1;j<10;j++){
            if(yuebin[i].junjia>yuebin[j].junjia){
                k=yuebin[i].junjia;
                yuebin[i].junjia=yuebin[j].junjia;
                yuebin[j].junjia=k;

            }
        }
    }*/
    for(i=0;i<n;i++){
        printf("%f\n",yuebin[i].junjia);
    }
	system("pause");
    less<i64>
}