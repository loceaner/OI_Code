#include<iostream>
using namespace std;
int x[2005],y[2005],s,n;
int main() {
	cin>>s>>n;
	for (int i=1; i<=n; i++)
		cin>>x[i]>>y[i];
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n-i; j++) {
			if (x[j]>x[j+1]) {
				swap(x[j],x[j+1]);
				swap(y[j],y[j+1]);
			}
		}
	}
	for (int i=1; i<=n; i++) {
		if (s>x[i]) {
			s+=y[i];
			continue;
		} else {
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}
