//s勾p防盗专用语句
//学习使我快乐，让我的人生更加美好
//例题做法，我自己打的
//第一遍没过，因为没开long long爆了 
#include<bits/stdc++.h>
using namespace std;

int size=0,n;
int h[50001]; 

void put(int d) {//s勾p的建堆函数 
	int now,next;
	h[++size]=d;
	now=size;
	while(now>1) {
		next=now/2;
		if(h[now]>=h[next])break;
		swap(h[now],h[next]);
		now=next;
	}
}

int get() {//s勾p的删元素函数 
	int now,next,res;
	res=h[1];
	h[1]=h[size--];
	now=1;
	while(now*2<=size) {
		next=now*2;
		if(next<size && h[next]>h[next+1])next++;
		if(h[now]<=h[next])break;
		swap(h[now],h[next]);
		now=next;
	}
	return res;
}

void work() {//s勾p的处理函数 
	int x,y,n,d;
	long long ans=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>d;
		put(d);
	}
	for(int i=1; i<n; i++) {
		x=get();
		y=get();
		ans+=x+y;
		put(x+y);
	}
	cout<<ans<<endl;
}

int main() {//s勾p的主函数 
	ios::sync_with_stdio(false);
	work();
	return 0;
}
