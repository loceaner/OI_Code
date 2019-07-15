//例题做法，我自己打的
#include<bits/stdc++.h>
using namespace std;

int size=0,n;
int h[50001];

void put(int d) {
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

int get() {
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

void work() {
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

int main() {
	ios::sync_with_stdio(false);
	work();
	return 0;
}
