#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
#include<stack>
#include<cstring>
#define inf 2147483647
#define ls rt<<1
#define rs rt<<1|1
#define lson ls,nl,mid,l,r
#define rson rs,mid+1,nr,l,r
#define N 100010
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define p(a) putchar(a)
#define g() getchar()
using namespace std;

int n,m;
int d[5010];
int l,r,v;
int s,t;
int x,y,z;
struct kru {
	int l;int r;int v;
	bool operator < (const kru &temp)const {return v>temp.v;}
} e[5010];


void in(int &x) {
	int y=1;char c=g();x=0;
	while(c<'0'||c>'9') {if(c=='-')y=-1;c=g();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0';c=g();}
	x*=y;
}

void o(int x) {if(x<0) {p('-');x=-x;}if(x>9)o(x/10);p(x%10+'0');}

int find(int x) {
	if(d[x]==x)return x;
	return d[x]=find(d[x]);
}

int gcd(int x,int y) {return y==0?x:gcd(y,x%y);}

int main() {
	in(n);in(m);
	For(i,1,m) {
		in(l);in(r);in(v);
		e[i].l=l;e[i].r=r;e[i].v=v;
	}
	in(s);in(t);
	x=inf;y=1;
	sort(e+1,e+m+1);
	For(i,1,m) {
		For(ii,1,n)
		d[ii]=ii;
		For(j,i,m) {
			int t1=find(e[j].l);
			int t2=find(e[j].r);
			if(t1!=t2)
				d[t1]=t2;
			if(find(s)==find(t)) {
				if(double(e[i].v)/double(e[j].v)<double(x)/double(y)) {
					x=e[i].v;
					y=e[j].v;
				}
				break;
			}
		}
	}
	if(x/y==inf) {
		cout<<"IMPOSSIBLE";
		return 0;
	}
	z=gcd(x,y);x/=z;y/=z;
	if(x%y==0)o(x/y);
	else cout<<x<<"/"<<y;
	return 0;
}

