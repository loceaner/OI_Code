#include <iostream>
#include <algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int  a[42][42];
int  b[42][42];
int x,y;
int ix,iy,jx,jy;
int r,c;
int dx[4]= {-1,0,1,0};
int dy[4]= {0,1,0,-1};
int ans=99999;
void dfs(int n,int m,int step,int xue) {
    if(xue==0) return;
    //�ⲻ����p2802����δ��֮�յĴ��𣿣���
    if(a[n][m]==4) xue=6;
    //��Ѫ
    if(step>r*c) return;
    //С�Ż�
    if(n==jx&&m==jy) {
        if(ans>step) ans=step;
        //���Ų���
        return;
    }
    for(int i=0; i<4; i++) {
        int tx=n+dx[i];
        int ty=m+dy[i];
        if(b[tx][ty]==0 && a[tx][ty]!=0) {
            b[tx][ty]=1;
            dfs(tx,ty,step+1,xue-1);
            b[tx][ty]=0;
            //���ݺ�
        }
    }
    return;
}

int main() {
    cin >> r >> c;
    for(int i = 0; i <= r+1; i++)
        for(int j = 0; j <= c+1; j++) {
            if(i == 0 || j == 0 || i == r+1 || j == c+1)
                a[i][j] = 0;
            else cin >> a[i][j];
            //�ӱ߽��Ƿ�������ж�Խ�磬���ͦ�鷳�ģ��ɴ�ѱ߽���һ�£�����һ��if,else�Ϳ�����ɱ߽������룬����Ҫ����ѭ���ֱ��
            if(a[i][j]==2) {
                ix=i;
                iy=j;
                a[i][j]=1;
                //������㣬��Ȼ�����ߣ��ɴ�Ҳ���1�ɣ�
            }

            if(a[i][j]==3) {
                jx=i;
                jy=j;
                a[i][j]=1;
                //�����ص㣬Ҳ���1���������
            }

        }
    dfs(ix,iy,0,6);
    //dfs(n,m,����,Ѫ��);
    if(ans!=99999)cout<<ans;
    else cout<<-1;
    //�ж��Ƿ��н�������û�����-1
    return 0;
}
