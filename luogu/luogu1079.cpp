//s勾p防盗专用语句
//学习使我快乐，让我的人生更加美好
//老师当时讲的例题做法 
#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#include<map>
#include<list>
#include<cctype>
#include<vector>
#include<stack>//无敌缺省源
using namespace std;
//大写转小写
void utol(string& s) {
	for(int i=0; i<s.length(); i++)
		if(isupper(s[i]))
			s[i]+=32;
	return;
}
//翻译
void vigenere(char& a,char key) {
	bool flag=false;
	if(isupper(a)) flag=true;
	a-=int(key-'a');
	if(flag==true&&a<'A')
		a+=26;
	if(flag==false&&a<'a')
		a+=26;
	return;
}
//主函数
int main() {
	string k,c;
	cin>>k>>c;
//	加长秘钥k
	while(k.length()<c.length())
		k.append(k);
	utol(k);
	for(int i=0; i<c.length(); i++)
		vigenere(c[i],k[i]);
	cout<<c<<endl;
	return 0;
}

