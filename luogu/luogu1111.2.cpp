#include<cstdio>
int f[6000][6000],f1[6000],n,m,x,y,z;
//f����Ϊ�ڽӾ���f[i][j]��ʾi��j֮��ߵ�Ȩֵ
//f1����Ϊ�������飬��¼��ǰ�ڵ��������ߵ�Ȩֵ
bool visit[6000];
//visit�����ʾ�ڵ��Ƿ��ڼ���V�У���Ϊ1������Ϊ0
void prim()
{
    int s=0,ans=0;
    //s��ʾ��������ʼΪ0
    while(s<n)
    //������С������
    {
        int minn=1<<30,to=0;
        //minnΪ��Ҫ����ߵ�Ȩֵ��toΪ��һ��
        s++;
        //����+1
        for(int i=1;i<=n;i++)
            if(!visit[i]&&f1[i]<minn)
            {
                minn=f1[i];
                to=i;
            }
        //Ѱ��Ҫ�����
        if(minn!=1<<30)ans=minn;
        //���з��������ı�ʱ�����´�
        for(int i=1;i<=n;i++)
            if(f1[i]>f[to][i]&&!visit[i])
                f1[i]=f[to][i];
        //����f1����
        visit[to]=1;
        //to���뼯��V
    }
    printf("%d",ans==0?-1:ans);
    //���������
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=1<<30;
    //��ʼΪ���޴󣬱�ʾ���ɴﵽ
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(f[x][y]>z)f[y][x]=f[x][y]=z;
    }
    //����ȨֵС��ԭȨֵʱ������Ȩֵ����ʵû�ã�
    for(int i=1;i<=n;i++)f1[i]=f[1][i];
    visit[1]=1;
    //���Ƚ��ڵ�1���뼯��V�����Լ�����һ�ڵ㣩
    prim();
    //����
}
