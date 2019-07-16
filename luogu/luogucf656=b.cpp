#include<bits/stdc++.h>

using namespace std;

int a[20],b[20];

int main() {
	double n,sum=0; 
	cin>>n;
	for(int i=0; i<n; i++)cin>>a[i];
	for(int i=0; i<n; i++)cin>>b[i];
	for(int i=0; i<1000000; i++)
		for(int j=0; j<n; j++)
			if(i%a[j]==b[j]) { 
				sum++; 
				break; 
			}
	cout<<setprecision(6)<<fixed<<sum/1000000;
	return 0;
}
