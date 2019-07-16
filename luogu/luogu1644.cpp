#include<iostream>
#include<cstdio>
using namespace std;

int n,m,tot;
int a[20][20];
int dx[4]= {1,2,2,1};
int dy[4]= {2,1,-1,-2};

int dfs(int i) {
	for(int j=0; j<=3; j++) {
		if(a[i-1][1]+dx[j]>=0&&a[i-1][1]+dx[j]<=m&&a[i-1][2]+dy[j]>=0&&a[i-1][2]+dy[j]<=n) {
			a[i][1]=a[i-1][1]+dx[j];
			a[i][2]=a[i-1][2]+dy[j];
			if(a[i][1]==m&&a[i][2]==n) tot++;
			else dfs(i+1);
		}
	}
}

int main() {
	a[1][1]=0,a[1][2]=0;
	cin>>n>>m;
	dfs(2);
	cout<<tot<<endl;
	return 0;
}
