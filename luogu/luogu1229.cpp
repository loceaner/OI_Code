#include<bits/stdc++.h>
using namespace std;
char a[5000],b[5000];
int main() {
	int i,j,x,y,n,ans=0;
	gets(a);
	gets(b);
	for (i=0; i<strlen(a); i++)
		for (j=1; j<strlen(b); j++)
			if (a[i]==b[j]&&a[i+1]==b[j-1])ans++;
	cout<<(1<<ans);
	return 0;
}
