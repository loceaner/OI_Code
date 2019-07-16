#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >sjp;
int n,a,b;
int main() {
	cin>>n;
	for(int i=1; i<=n; ++i) {
		cin>>a;
		if(a==1) {
			cin>>b;
			sjp.push(b);
		} else if(a==2) {
			cout<<sjp.top()<<"\n";
		} else if(a==3) {
			sjp.pop();
		}
	}
	return 0;
}

