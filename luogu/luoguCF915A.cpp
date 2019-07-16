#include<cstdio>
int main() 
{
	int n,k,i,min=1000000,ans=0,t;
	scanf("%d %d",&n,&k);
	for(i=0; i<n; i++) 
	{
		scanf("%d",&t);
		if(k%t==0) 
		{
			ans=k/t;
			if(ans<min)
				min=ans;
		}
	}
	printf("%d",min);
	return 0;
}
