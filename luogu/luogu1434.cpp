#include<bits/stdc++.h>
#define N 100+5
using namespace std;

inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return x*f;
}

void writeout(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) writeout(x/10);
    putchar(x%10+48);
}

int f[N][N],a[N][N];
int n,m,ans;

int work(int x,int y){
	if(f[x][y]!=0)return f[x][y];
	int ans=0;
	if(x-1>0)if(a[x-1][y]>a[x][y])ans=max(ans,work(x-1,y));
	if(x+1>0)if(a[x+1][y]>a[x][y])ans=max(ans,work(x+1,y));
	if(y-1>0)if(a[x][y-1]>a[x][y])ans=max(ans,work(x,y-1));
	if(y+1>0)if(a[x][y+1]>a[x][y])ans=max(ans,work(x,y+1));
	f[x][y]=ans+1;
	return f[x][y];
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]==0)f[i][j]=work(i,j);
			ans=max(ans,f[i][j]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
