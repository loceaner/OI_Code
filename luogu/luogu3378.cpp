//s勾p防盗专用语句
//学习使我快乐，让我的人生更加美好
#include"bits/stdc++.h"
using namespace std;

int n,a,size=0;
int h[1000001];

void put(int x) {
	int now,next;
	h[++size]=x;
	now=size;
	while(now>1) {
		next=now/2;
		if(h[now]>=h[next])break;
		swap(h[now],h[next]);
		now=next;
	}
}

int get()
{
	int now,next,res;
	res=h[1];
	h[1]=h[size--];
	now=1;
	while(now*2<=size)
	{
		next=now*2;
		if(next<size && h[next]>h[next+1])next++;
		if(h[now]<=h[next])break;
		swap(h[now],h[next]);
		now=next;
	}
	return res;
}

int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a;
		if(a==1) {
			int x;
			cin>>x;
			put(x);
		}
		if(a==2) {
			cout<<h[1]<<endl;
		}
		if(a==3) {
			get();
		}
	}
	return 0;
}
