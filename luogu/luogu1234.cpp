#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#define N 1010
using namespace std;

char a[N][N];
int n,m;
long long ans=0;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='h'){
				if(a[i+1][j]=='e'&&a[i+2][j]=='h'&&a[i+3][j]=='e')ans++;
				if(a[i][j+1]=='e'&&a[i][j+2]=='h'&&a[i][j+3]=='e')ans++;
				if(a[i-1][j]=='e'&&a[i-2][j]=='h'&&a[i-3][j]=='e')ans++;
				if(a[i][j-1]=='e'&&a[i][j-2]=='h'&&a[i][j-3]=='e')ans++;				
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
