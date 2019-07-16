#include<cstdio>
using namespace std;

int a,sum=0;

int main() {
	scanf("%d",&a);
	while(a) {
		if(a%8==1)
			sum++;
		a/=8;
	}
	printf("%d\n",sum);
	return 0;
}
