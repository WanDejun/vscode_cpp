#include <stdio.h>
#define inf 0x3f3f3f3f
int map[1000][1000];
int main()
{
    int k,i,j,n,m;
    //读入n和m，n表示顶点个数，m表示边的条数
    scanf("%d %d",&n,&m);

    //初始化
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(i==j)
                map[i][j]=0;
            else
                map[i][j]=inf;
    int a,b,c;
    //读入边
    for(i=1; i<=m; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        map[a][b]=c;//这是一个有向图
    }

    //Floyd-Warshall算法核心语句
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if(map[i][j]>map[i][k]+map[k][j] )
                    map[i][j]=map[i][k]+map[k][j];

    //输出最终的结果,最终二维数组中存的即使两点之间的最短距离
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("%10d",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}
