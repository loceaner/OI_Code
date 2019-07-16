/*众所周知，sort一定会超时，所以我要用sort
然而我的stable_sort只T了两个点，加个O_2就能过去了，太诡异了 */
#include<bits/stdc++.h>
#define N 200011
using namespace std;

struct node{
	int num;
	int score;
	int worth;
}a[N];

int n,r,q;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}

bool cmp(node x,node y){
	return x.score==y.score ? x.num<y.num : x.score>y.score;
}

int main(){
	n=read(),r=read(),q=read();
	for(int i=1;i<=2*n;i++){
		a[i].score=read();
		a[i].num=i;
	}
	for(int i=1;i<=2*n;i++){
		a[i].worth=read();
	}
	stable_sort(a+1,a+1+2*n,cmp);
	for(int i=1;i<=r;i++){
		for(int j=1;j<=n;j++){
			if(a[j*2-1].worth>a[j*2].worth)a[j*2-1].score++;
			else a[j*2].score++;
		}
		stable_sort(a+1,a+1+2*n,cmp);
	}
	cout<<a[q].num<<'\n';
}
