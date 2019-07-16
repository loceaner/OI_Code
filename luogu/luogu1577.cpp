//切绳子 二分答案 
#include<bits/stdc++.h>
using namespace std;

const int X=10010;
const double inf=20040131;
double l[X];
int n,k;
int ans;

inline int read() {
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return x*f;
}

bool judge(double x) {
	int num=0;
	for(int i=1; i<=n; i++) {
		num+=(int)(l[i]/x);
	}
	return num>=k;
}

void solve() {
	double left=0,right=inf;
	for(int i=1; i<=100; i++) {
		double mid=(left+right)/2;
		if(judge(mid))left=mid;
		else right=mid;
	}
	printf("%.2lf\n",floor(right*100)/100);
}

int main() {
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++) {
		scanf("%lf",&l[i]);
	}
	solve();
	return 0;
}
