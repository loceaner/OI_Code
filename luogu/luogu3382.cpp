#include<bits/stdc++.h>
#define db double
#define N 20
using namespace std;

const db eps=1e-6;
int n;
db a[20],l,r,mid,mmid,k;

db f(db x){
	db s=0;
	for(int i=0;i<=n;i++)s=s*x+a[i];//秦九韶公式,自行百度 
	return s; 
}

int main(){
	scanf("%d%lf%lf",&n,&l,&r);
	for(int i=0;i<=n;i++){
		scanf("%lf",&a[i]);
	}
	while(r-l>=eps){
		k=(r-l)/3.0;
		mid=l+k;
		mmid=r-k;
		if(f(mid)>f(mmid))r=mmid;
		else l=mid;
	}
	printf("%.5lf\n",l);
	return 0;
}
