#include<iostream>
using namespace std;
char a;
int x,fl;
inline int ab(int a) {
	if(a<0) 
	return -a;
	else return a; 
}
int main() {
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++) {
			cin>>a;
			if(a!='-') {
				x++;
				if(a=='X'&&ab(i-j)==1)fl=1;
			}
		}
	if(fl)cout<<"xiaoa will win.\n";
	else cout<<"Dont know.\n";
	cout<<x;
}
