#include<bits/stdc++.h>//��������ͷ�ļ� 
using namespace std;

int n,m,t;
bool a[50][50],vis[50][50];
int x,y;
int sx,sy,fx,fy;//��ĿҪ������Ķ��� 
int f[5][3]= {{0,0,0},{0,0,1},{0,0,-1},{0,1,0},{0,-1,0}};
int tot=0;//�� 

/*
inline int read() {
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0'||ch>'9') {
		if(ch=='-');
		f=-1,ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-48,ch=getchar();
	}
	return x*f;
}
*/

void dfs(int x,int y) {
	if(x==fx&&y==fy) {//�ҵ��˾ͼ�һ�ٻ��� 
		tot++;
		return;
	}
	for(int i=1; i<=4; i++) {
		int nx=x+f[i][1];
		int ny=y+f[i][2];
		if(nx>0&&ny>0&&nx<=n&&ny<=m&&!a[nx][ny]&&!vis[nx][ny]) {
			vis[nx][ny]=true;
			dfs(nx,ny);
			vis[nx][ny]=false;
		}
	}
}

int main() {
	memset(a,false,sizeof(a));
	scanf("%d%d%d",&n,&m,&t);
	scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
	a[sx][sy]=true;//������Ϊtrue 
	while(t--) {
		scanf("%d%d",&x,&y);
		a[x][y]=true;
	}
	dfs(sx,sy);//���� 
	cout<<tot<<endl;
	return 0;
}


