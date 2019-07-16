#include<cstdio>
using namespace std;
int l[11];
int f,e,t;
int main() {
	scanf("%d%d%d",&f,&e,&t);
	for(int i=1; i<=f; i++) {
		for(int j=1; j<=e; j++) {
			char c;
			scanf(" %c",&c);
			if(c=='Y')l[j]++;
		}
	}
	int ans=0;
	for(int i=1; i<=e; i++)if(l[i]>=t)ans++;
	printf("%d",ans);
	return 0;
}
