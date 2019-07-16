#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[101][101];
bool f[101][101];
int ans=0;

void shensou(int x,int y) {
	if(x<1||y<1||x>n||y>m) {
		return ;
	}
	if((a[x][y+1]!='0')) {
		a[x][y+1]='0';
		shensou(x,y+1);
	}
	if((a[x][y-1]!='0')) {
		a[x][y-1]='0';
		shensou(x,y-1);
	}
	if((a[x+1][y]!='0')) {
		a[x+1][y]='0';
		shensou(x+1,y);
	}
	if((a[x-1][y]!='0')) {
		a[x-1][y]='0';
		shensou(x-1,y);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=false;
		}
	}*/
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(a[i][j]!='0') {
				a[i][j]=0;
				ans++;
				shensou(i,j);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
