#include<iostream>
#include<cmath>
using namespace std;
const int maxn=100000;
int tree[100000];
int con=0;
int m,n,total,w,h,last;
char p[4096][4096];

int get(int x,int y) {
	return pow(2,x-1)-1+y;
}

void del(int id) {
	if (id>total) return;
	tree[id]=0;
	del(id*2);
	del(id*2+1);
} //É¾½Úµã

void draw(int id,int& x,int& y) {
	if (id>last) {
		int tmp=id-last;
		x=h;
		y=6*((tmp-1)/2)+(tmp%2!=0?1:5);
		if (tree[id]) p[x][y]='o';
		else con++;
		return;
	}
	int lx,ly,rx,ry;
	draw(id<<1,lx,ly);
	draw(id<<1|1,rx,ry);
	y=(ly+ry)/2;
	x=lx-(ry-ly)/2;
	if (tree[id]) {
		p[x][y]='o';
		for (int i=1; i<(ry-ly)/2; i++) {
			if (tree[id*2])p[x+i][y-i]='/';
			if (tree[id*2+1]) p[x+i][y+i]='\\';
		}
	} else {
		con++;
	}
}

int main() {
	cin>>m>>n;
	total=pow(2,m)-1;
	int n0=pow(2,m-1);
	w=n0/2*5+n0/2-1;
	h=w/2+1;
	last=pow(2,m-1)-1;
	for (int i=1; i<=(1<<m); i++) {
		tree[i]=1;
	}
	for (int i=1; i<=n; i++) {
		int x,y;
		cin>>x>>y;
		int id=get(x,y);
		del(id);
	}
	int x,y;
	draw(1,x,y);
	for (int i=1; i<=h; i++) {
		for (int j=1; j<=w; j++) {
			if (p[i][j]=='o'||p[i][j]=='/'||p[i][j]=='\\') {
				cout<<p[i][j];
			} else cout<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
