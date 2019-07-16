#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 2333
using namespace std;
inline int read();
int n,an;
char a[maxn];
int main() {
	n=read();
	memset(a,0,sizeof(a));
	scanf(" %s",a+1);
	sort(a+1,a+n+1);
	printf("%s\n",a+1);
	an=1;
	while(next_permutation(a+1,a+n+1)) {
		printf("%s\n",a+1);
		an++;
	}
	printf("%d",an);
	return 0;
}
inline int read() {
	int ans=0,f=1;
	char c=getchar();
	while('0'>c||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')ans=ans*10+c-48,c=getchar();
	return ans*f;
}
