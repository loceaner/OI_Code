#include<bits/stdc++.h>
using namespace std;

const int MOD=pow(2,31);
int f[50],n,cnt;

int main(){
	scanf("%d",&n);
	f[1]=f[2]=1;
	for(int i=3;i<=n;i++){
		f[i]=(f[i-1]+f[i-2])%MOD;
	}
	cout<<f[n]<<"=";
	for(int i=2;i<=f[n];i++){
		while(f[n]%i==0){
			cnt++;
			if(cnt==1)cout<<i;
			else cout<<"*"<<i;
			f[n]/=i;
		}
	}
	return 0;
}
