#include<bits/stdc++.h>//��������ͷ�ļ� 
using namespace std;

int a[10][10];//ˮˮ������ 
bool vis[10][10];
int ans=0x3f;
int n,m;
int ix,iy,jx,jy;
int dx[5]= {0,0,0,-1,1};//�����������ĸ�������� 
int dy[5]= {0,-1,1,0,0};

void dfs(int x,int y,int step,int blo) {
	if(blo==0)return;
	if(a[x][y]==4)blo=6;//�������ͻ���Ѫ 
	if(x==jx&&y==jy) {
		if(ans>step)ans=step;
		return;
	}
	for(int i=1; i<=4; i++) {
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(vis[nx][ny]==0&&a[nx][ny]!=0) {
			vis[nx][ny]=1;
			dfs(nx,ny,step+1,blo-1);
			vis[nx][ny]=0;//���� 
		}
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%d",&a[i][j]);
			if(a[i][j]==2) {
				ix=i,iy=j;//������� 
				a[i][j]=1;
			}
			if(a[i][j]==3) {
				jx=i,jy=j;//�յ����� 
				a[i][j]=1;
			}
		}
	}
	dfs(ix,iy,0,6);
	if(ans!=0x3f)cout<<ans;
	else cout<<-1;
	return 0;
}
