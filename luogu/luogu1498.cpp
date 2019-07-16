#include<bits/stdc++.h>//sjp的懒人万能头 
using namespace std;

int n,a[10001]= {1};

int main() {
	cin>>n;
	for(int i=0; i<1<<n; i++) {
		for(int j=1; j<(1<<n)-i; ++j)
			cout<<" ";
		for(int k=i; k>=0; --k)a[k]^=a[k-1];
		if(!(i%2))for(int d=0; d<=i; d++) {
				if(a[d])cout<<"/\\";
				else cout<<"  ";
			}
		else for(int l=0; l<=i; l+=2) {
				if(a[l])cout<<"/__\\";
				else cout<<"    ";
			}
		cout<<"\n";
	}
	return 0;
}

