#include <cstdio>

int n, m, a[105], ans, visit[105];

void dfs(int s, int sum)
{
    if(sum >= m)
    {
        if(sum==m)
            ans++;
        return;
    }
    for(int i=s; i<=n; i++)
    {
        if(!visit[i])
        {
            visit[i] = 1;
            dfs(i,sum+a[i]);
            visit[i] = 0;
        }
    }
}


int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", a+i);
    }
    dfs(1, 0);
    printf("%d", ans);
    return 0;
}
