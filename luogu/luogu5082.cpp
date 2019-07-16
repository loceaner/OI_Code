#include <cstdio>
using namespace std;
double n,a=0,b=0;
int main() {
	scanf("%lf",&n);
	for(int i=1; i<=n; i++) {
		double t;
		scanf("%lf",&t);
		a+=t;
	}
	for(int i=1; i<=n; i++) {
		double t;
		scanf("%lf",&t);
		b+=t;
	}
	printf("%.6lf\n",(3*a-2*b)/(a-b));
	return 0;
}
