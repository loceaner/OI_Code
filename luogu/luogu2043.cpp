#include<iostream>
using namespace std;
int a[10001]= {0},n; 
int main() {
	cin>>n;
	for (int i=2; i<=n; i++) { 
		int i2=i;  
		for (int j=2; j<=i; j++)
			while (i2%j==0) {
				a[j]++;
				i2/=j;
			}
	}
	for (int i=1; i<=10000; i++) 
		if (a[i]!=0)
			cout<<i<<" "<<a[i]<<endl;
}
