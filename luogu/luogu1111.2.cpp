#include<cstdio>
int f[6000][6000],f1[6000],n,m,x,y,z;
//f数组为邻接矩阵，f[i][j]表示i与j之间边的权值
//f1数组为辅助数组，记录当前节点与其他边的权值
bool visit[6000];
//visit数组表示节点是否在集合V中，在为1，不在为0
void prim()
{
    int s=0,ans=0;
    //s表示边数，初始为0
    while(s<n)
    //建立最小生成树
    {
        int minn=1<<30,to=0;
        //minn为所要加入边的权值，to为另一端
        s++;
        //边数+1
        for(int i=1;i<=n;i++)
            if(!visit[i]&&f1[i]<minn)
            {
                minn=f1[i];
                to=i;
            }
        //寻找要加入边
        if(minn!=1<<30)ans=minn;
        //当有符合条件的边时，更新答案
        for(int i=1;i<=n;i++)
            if(f1[i]>f[to][i]&&!visit[i])
                f1[i]=f[to][i];
        //更新f1数组
        visit[to]=1;
        //to加入集合V
    }
    printf("%d",ans==0?-1:ans);
    //输出及特判
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=1<<30;
    //初始为无限大，表示不可达到
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(f[x][y]>z)f[y][x]=f[x][y]=z;
    }
    //仅当权值小于原权值时，更新权值（其实没用）
    for(int i=1;i<=n;i++)f1[i]=f[1][i];
    visit[1]=1;
    //首先将节点1加入集合V（可以加入任一节点）
    prim();
    //建树
}
