#include<iostream>
#include<cstdio>
#include<string>//´¿´¿´¿±©Á¦£¡£¡£¡£¡£¡ 
using namespace std;
string a;
int ans;
int main() {
	getline(cin,a);
	for(int i=0; i<a.size(); i++) {
		if(a[i]==' '||a[i]=='a'||a[i]=='d'||a[i]=='g'||a[i]=='j'||a[i]=='m'||a[i]=='p'||a[i]=='t'||a[i]=='w') ans++;
		if(a[i]=='b'||a[i]=='e'||a[i]=='h'||a[i]=='k'||a[i]=='n'||a[i]=='q'||a[i]=='u'||a[i]=='x') ans+=2;
		if(a[i]=='c'||a[i]=='f'||a[i]=='i'||a[i]=='l'||a[i]=='o'||a[i]=='r'||a[i]=='v'||a[i]=='y') ans+=3;
		if(a[i]=='s'||a[i]=='z') ans+=4;
	}
	cout<<ans;
	return 0;
}
