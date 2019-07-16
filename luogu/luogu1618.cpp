#include<bits/stdc++.h>
using namespace std;

int a,b,c,f;
int j,k;

int main() {
	cin>>a>>b>>c;
	for(int i=(123/a+min(123%a,1))*a; i<=987/a*a; i+=a) {
		j=i/a*b;
		k=i/a*c;
		if(j>=100&&j<=999&&k>=100&&k<=999){
			int s[10],sum=0,ch=1;
			s[1]=i/100;
			s[2]=i/10%10;
			s[3]=i%10;
			s[4]=j/100;
			s[5]=j/10%10;
			s[6]=j%10;
			s[7]=k/100;
			s[8]=k/10%10;
			s[9]=k%10;
			for(int o_o=1;o_o<=9;o_o++){
				sum+=s[o_o];
				ch*=s[o_o];
			}
			if(sum==45&&ch==362880){
				f=1;
				printf("%d %d %d\n",i,j,k);
			}
		}
	}
	if(f==0){
		cout<<"No!!!"<<endl;
	}
	return 0;
}
