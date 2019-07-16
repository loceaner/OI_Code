#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int zd[1001],m;
bool find(int x) {
	int i;
	for(i=1; i<=m; i++)
		if(zd[i]==x)return true;
	return false;
}
int i,n,j,k,z;
int main() {
	memset(zd,-1,sizeof(zd));
	cin>>m>>n;
	for(i=1; i<=n; i++) {
		scanf("%d",&z);
		if(!find(z)) {
			j++;
			k++;
			while(k>m)k-=m;
			zd[k]=z;
		}
	}
	cout<<j;
	return 0;
}
