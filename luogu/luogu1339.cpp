#include<bits/stdc++.h>
#define N 7000
using namespace std;

int n,m,ans,cnt,S,T;
int head[N],d[N];
bool vis[N];
struct edge{
    int u,v,net,dis;
    bool operator < (const edge &a)const{
            return dis>a.dis;
    }
}e[N<<1],p;

inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

inline void add(int u,int v,int dis)
{
    e[++cnt].v=v;e[cnt].dis=dis;e[cnt].net=head[u];head[u]=cnt;
}

void dijkstra(int u)
{
    priority_queue<edge>q;
    p.u=u;p.dis=0;q.push(p);    
    memset(d,0x3f,sizeof d);d[S]=0;
    while(!q.empty())
    {
        edge tmp=q.top();q.pop();
        if(vis[tmp.u]) continue;
        vis[tmp.u]=true;
        for(int i=head[tmp.u];i;i=e[i].net)
        {
            int v=e[i].v;
            if(d[v]>d[tmp.u]+e[i].dis)
            {
                d[v]=d[tmp.u]+e[i].dis;
                p.u=v;p.dis=d[v];q.push(p);
            }
        }
    }
}

int main()
{
    int x,y,z; 
    n=read();m=read();S=read();T=read();
    for(int i=1;i<=m;i++)
    {
        x=read();y=read();z=read();
        add(x,y,z);add(y,x,z);
    }
    dijkstra(S);
    printf("%d\n",d[T]);
    return 0;
}
