#include<bits/stdc++.h>
using namespace std;

int n,sum,ans;
int num[1001],f[1001],wei[7]= {0,1,2,3,5,10,20};

int main() {
	for(int i=1; i<=6; i++) {
		scanf("%d",&num[i]);
		sum+=num[i]*wei[i];
	}
	f[0]=1;
	for(int i=1; i<=6; i++)
		for(int j=1; j<=num[i]; j++)
			for(int k=sum; k>=wei[i]; k--)
				if(f[k-wei[i]])
					f[k]=1;
	for(int i=1; i<=sum; i++)
		if(f[i])ans++;
	printf("Total=%d\n",ans);
	return 0;
}
