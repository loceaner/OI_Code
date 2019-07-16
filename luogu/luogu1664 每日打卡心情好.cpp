#include <cstdio>//建鑫保理出奇迹 
#include <cmath>
using namespace std;
int n;
int t1=0,w=0;
double m=0;
int a[1000+5];
int main() {
	scanf ("%d",&n);
	for (int i=1; i<=n; i++)
		scanf ("%d",&a[i]);
	for (int i=1; i<=n; i++) {
		if (a[i]==1) {
			m=0;
			t1++;
			if (t1<3)
				w++;
			if (t1>=3&&t1<7)
				w+=2;
			if (t1>=7&&t1<30)
				w+=3;
			if (t1>=30&&t1<120)
				w+=4;
			if (t1>=120&&t1<365)
				w+=5;
			if (t1>=365)
				w+=6;
		} else {
			m++;
			if (a[i+1]==1)
				t1-=pow(2,m-1);
			if (t1<0)
				t1=0;
		}
	}
	printf ("%d",w);

}
