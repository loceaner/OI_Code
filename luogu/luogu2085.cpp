#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m,k;
const int maxn=10000;
int a[maxn+10],b[maxn+10],c[maxn+10];
struct point {
	int x,y,f;
} heap[maxn+10];

int work(int i,int x) {
	return (a[i]*x*x+b[i]*x+c[i]);
}

void insert(int f,int x,int y) {
	int i=++k;
	heap[i].f=f;
	heap[i].x=x;
	heap[i].y=y;
	while (i>1 && heap[i].y<heap[i>>1].y) {
		swap(heap[i],heap[i>>1]);
		i=i>>1;
	}
}

void _delete() {
	heap[1]=heap[k--];
	int i=1,j=2;
	if (j+1<=k && heap[j+1].y<heap[j].y) j++;

	while (j<=k && heap[j].y<heap[i].y) {
		swap(heap[j],heap[i]);
		i=j;
		j=j<<1;
		if (j+1<=k && heap[j+1].y<heap[j].y) j++;
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) {
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		insert(i,1,work(i,1));
	}
	for (int i=0; i<m; i++) {
		printf("%d ",heap[1].y);
		int x=heap[1].x,f=heap[1].f;
		_delete();
		insert(f,x+1,work(f,x+1));
	}
	return 0;
}

