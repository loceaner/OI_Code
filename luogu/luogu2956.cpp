#include<cstdio>
#include<iostream>
using namespace std;
bool p[250][250];
int main() {
	int x,y,n,s=0,a,b,c,d;
	cin>>x>>y>>n;
	for(int m=1; m<=n; m++) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int i=a; i<=c; i++)
			for(int j=b; j<=d; j++) p[i][j]=1;
	}
	for(int i=1; i<=x; i++)
		for(int j=1; j<=y; j++)
			if(p[i][j]) s++;
	cout<<s<<endl;
	return 0;
}
