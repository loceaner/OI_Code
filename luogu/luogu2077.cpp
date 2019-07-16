#include<iostream>
#include<cstdio>
using namespace std;

int m,ai[100011],ri[100010],gi[100010];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)cin>>ai[i];
	for(int i=1;i<=n;i++)cin>>ri[i];
	for(int i=1;i<=n;i++)cin>>gi[i];
	for(int i=1;i<=n;i++)
    {
        if (i>=2)
        m+=ai[i-1];
        else
        m+=0;
        if(gi[i]<m%(ri[i]+gi[i])) 
            m+=(ri[i]+gi[i]-m%(ri[i]+gi[i]));
        printf("%d\n",m);
    }
    return 0;
}
