#include<bits/stdc++.h>
#define N 100101
using namespace std;

int a[N],b[N];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	sort(b+1,b+1+m);
	for(int i=1;i<=n;i++){
		int l=1,r=m;
		while(l<=r){
			int mid=(l+r)/2;
			if(b[mid]==a[i]){
				cout<<a[i]<<" ";
				break;
			}else if(b[mid]<a[i])l=mid+1;
			else r=mid-1;
		}
	}
	return 0;
}
