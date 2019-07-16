#include<cstdio>
using namespace std;
int n,m,a,p;
int yue[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
int main() {
	scanf("%d %d",&n,&m);
	for(int i=1; i<=12; i++)
		for(int j=1; j<=yue[i-1]; j++) {
			a=(j%10)*1000+(j/10)*100+(i%10)*10+i/10;
			if(a<(n/10000)||a>(m/10000))
				continue;
			p++;
		}
	if(n<=92200229&&m>=92200229)p++;
	printf("%d",p);
}
