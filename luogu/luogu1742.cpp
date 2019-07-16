#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main() {
	long long t,n,i;
	char x[101],z[101];
	cin>>n>>x>>z;
	for (i=0; i<n; i++)
		if (x[i]<z[i]) {
			cout<<-1<<endl;
			return 0;
		}
	cout<<z<<endl;
	return 0;
}
