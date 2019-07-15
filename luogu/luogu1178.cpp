#include<bits/stdc++.h>
using namespace std;

int f[13]={0,0,31,60,91,121,152,182,213,244,274,305,335};
int data[500];
double k;
int n,m,d;
long long tem,bi,sum;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&m,&d);
		tem=f[m];
		tem+=d;
		data[tem]=1;
	}
	for(int i=1;i<=366;i++){
		if(data[i]==1){
			sum=0;
		}else sum++;
		if(sum>bi)bi=sum;
	}
	k=bi*24*60*60*1.0/366;
	cout<<fixed<<setprecision(0)<<k;
	return 0;
} 
