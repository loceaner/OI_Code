#include<iostream>
using namespace std;
int main() {
	int n,a,t;
	cin>>n;
	t=n;
	for(int i=1; i<t; i++) {
		t=t-i;
		a=i;
	}
	a++;
	if(a%2==0) {
		cout<<t<<"/"<<a-t+1<<endl;
	} else {
		cout<<a-t+1<<"/"<<t<<endl;
	}
	return 0;
}

