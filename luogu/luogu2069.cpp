#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cmath>
#include<iomanip>
#include<list>
using namespace std;

const int maxn=1e4+10; 
int sign[maxn];
int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	int tall=1;
	for(int i=1;i<=n;i++)sign[i]=i;
	for(int i=1;i<=m;i++)
	{
		int skip=(i*i*i)%5+1;
		tall=tall+skip;
		if(tall>n-i+1)tall=skip+1;
		if(i!=m){
			for(int j=tall+1;j<=n-i+1;j++){
				sign[j-1]=sign[j];
			}
		}
	}
	printf("%d",sign[tall]);
	return 0;
}
