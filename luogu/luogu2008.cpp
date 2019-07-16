#include<cstring>
#include<iostream>
using namespace std;

int n,a[10010],b[10010],c[10010];
bool vis[10010];

int main() 
{
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=n; i++) {
		b[i]=1;
		for(int j=1; j<=i-1; j++)
			if(a[i]>=a[j])
				if(b[i]<b[j]+1) {
					b[i]=b[j]+1;
					c[i]=c[j];
				}
		c[i]+=a[i];
	}
	for(int i=1; i<=n; i++)cout<<c[i]<<" ";
	return 0;
}
