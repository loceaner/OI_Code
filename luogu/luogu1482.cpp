#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int a1,a2,b1,b2;
char abc;
int main() {
	scanf("%d",&a1);
	abc=getchar();
	scanf("%d",&b1);
	scanf("%d",&a2);
	abc=getchar();
	scanf("%d",&b2);
	int c1=a1*a2,c2=b2*b1;
	printf("%d %d\n",c2 / __gcd(c1,c2),c1 / __gcd(c1,c2));
	return 0;
}
