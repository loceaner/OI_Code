#include<bits/stdc++.h>
using namespace std;

int n,m;
int ans;

struct node{
	int a,b;
}a[5005];

bool cmp(node x,node y){
	return x.a<y.a;
}

inline int read(){
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}

int main(){
	n=read(),m=read();
	
	for(int i=1;i<=m;i++){
		a[i].a=read(),a[i].b=read();
	} 
	sort(a+1,a+1+m,cmp);
	int i=1;
	while(n!=0){
		if(a[i].b!=0){
			a[i].b--;
			ans+=a[i].a;
			n--;
		}
		else i++;
	}
	cout<<ans<<'\n';
	return 0;
}
