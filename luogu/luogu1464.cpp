#include <cstdio>
using namespace std;

int s[21][21][21];
long long int a[1000],b[1000],c[1000];
int a1[1000],b1[1000],c1[1000];

int w(int a,int b,int c) 
{
	if(a<=0||b<=0||c<=0) return 1;
	if(s[a][b][c]) return s[a][b][c];
	else if(a>20||b>20||c>20) s[a][b][c]=w(20,20,20);
	else if(a<b&&b<c) s[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else s[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	return s[a][b][c];
}

int main() 
{
	int result[100];
	int i=0;
	int j=0;
	while(1) {
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		if(a[i]==-1&&b[i]==-1&&c[i]==-1)
			break;
		if(a[i]>21||b[i]>21||c[i]>21)
			a1[i]=b1[i]=c1[i]=21;
		else {
			a1[i]=a[i];
			b1[i]=b[i];
			c1[i]=c[i];
		}
		result[i]=w(a1[i],b1[i],c1[i]);
		i++;
	}
	for(j=0; j<i; j++) {
		printf("w(%lld, %lld, %lld) = %d\n",a[j],b[j],c[j],result[j]);
	}
	return 0;
}
