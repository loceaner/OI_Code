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
    //这不就是p2802两大未解之谜的答案吗？（雾
    if(a[n][m]==4) xue=6;
    //加血
    if(step>r*c) return;
    //小优化
    if(n==jx&&m==jy) {
        if(ans>step) ans=step;
        //择优步数
        return;
    }
    for(int i=0; i<4; i++) {
        int tx=n+dx[i];
        int ty=m+dy[i];
        if(b[tx][ty]==0 && a[tx][ty]!=0) {
            b[tx][ty]=1;
            dfs(tx,ty,step+1,xue-1);
            b[tx][ty]=0;
            //回溯吼啊
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
            //加边界是方便后面判断越界，真的挺麻烦的，干脆把边界标记一下，而且一对if,else就可以完成边界与输入，不需要两个循环分别搞
            if(a[i][j]==2) {
                ix=i;
                iy=j;
                a[i][j]=1;
                //这是起点，既然可以走，干脆也标记1吧！
            }

            if(a[i][j]==3) {
                jx=i;
                jy=j;
                a[i][j]=1;
                //这是重点，也标记1，别搞特殊
            }

        }
    dfs(ix,iy,0,6);
    //dfs(n,m,步数,血量);
    if(ans!=99999)cout<<ans;
    else cout<<-1;
    //判断是否有结果，如果没有输出-1
    return 0;
}
