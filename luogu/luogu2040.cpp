#include<bits/stdc++.h>
using namespace std;

int ans=9;
int a[10][10];

bool judge(){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(a[i][j]==0)
				return 0;
		}
	}
	return 1;
}

void dfs(int s){
	if(s>ans)return;
	if(judge()==1){if(ans>s)ans=s;return;}
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			a[i][j]=1-a[i][j];
			if(i+1<4)a[i+1][j]=1-a[i+1][j];
			if(i-1>0)a[i-1][j]=1-a[i-1][j];
			if(j+1<4)a[i][j+1]=1-a[i][j+1];
			if(j-1>0)a[i][j-1]=1-a[i][j-1];
			dfs(s+1);
			a[i][j]=1-a[i][j];
			if(i+1<4)a[i+1][j]=1-a[i+1][j];
			if(i-1>0)a[i-1][j]=1-a[i-1][j];
			if(j+1<4)a[i][j+1]=1-a[i][j+1];
			if(j-1>0)a[i][j-1]=1-a[i][j-1];
		}
	}
	return;
}

int main() {
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++)
			cin>>a[i][j];
	dfs(0);
	cout<<ans;
	return 0;
}
