#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<list>
#include<algorithm> 
using namespace std;
int x,y,n,i,xs[6666],ys[6666],sjp,s1,s2;
int main() {
	cin>>n;
	for(i=1; i<=n; i++) {
		cin>>x>>y;
		if(!xs[x]) s1++;
		if(!ys[y]) s2++;
		xs[x]=1,ys[y]=1;
	}
	if(s1>s2)sjp=s2;
	else sjp=s1;
	cout<<sjp;
	return 0;
}
