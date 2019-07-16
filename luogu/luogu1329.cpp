#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN = 10001;
inline void read(int &n) {
	char c=getchar();
	n=0;
	bool flag=0;
	while(c<'0'||c>'9')    c=='-'?flag=1,c=getchar():c=getchar();
	while(c>='0'&&c<='9')    n=n*10+c-48,c=getchar();
	flag==1?n=-n:n=n;
}
int a[MAXN];
int b[MAXN];
int n;
int la,lb;
int ansa,ansb;
int main() {
	read(n);
	read(la);
	read(lb);
	for(int i=1; i<=la; i++)    read(a[i]);
	for(int i=1; i<=lb; i++)    read(b[i]);
	int nowa=1,nowb=1;
	for(int i=1; i<=n; i++) {
		if(a[nowa]==0) {
			if(b[nowb]==1)    ansb++;
			if(b[nowb]==2)    ansa++;
			if(b[nowb]==3)    ansa++;
			if(b[nowb]==4)    ansb++;
		}
		if(a[nowa]==1) {
			if(b[nowb]==0)    ansa++;
			if(b[nowb]==2)    ansb++;
			if(b[nowb]==3)    ansa++;
			if(b[nowb]==4)    ansb++;
		}
		if(a[nowa]==2) {
			if(b[nowb]==0)    ansb++;
			if(b[nowb]==1)    ansa++;
			if(b[nowb]==3)    ansb++;
			if(b[nowb]==4)    ansa++;
		}
		if(a[nowa]==3) {
			if(b[nowb]==0)    ansb++;
			if(b[nowb]==1)    ansb++;
			if(b[nowb]==2)    ansa++;
			if(b[nowb]==4)    ansa++;
		}
		if(a[nowa]==4) {
			if(b[nowb]==0)    ansa++;
			if(b[nowb]==1)    ansa++;
			if(b[nowb]==2)    ansb++;
			if(b[nowb]==3)    ansb++;
		}
		nowa++;
		nowb++;
		if(nowa>la)    nowa=1;
		if(nowb>lb)    nowb=1;
	}
	printf("%d %d",ansa,ansb);
	return 0;
}
