//s��p����ר�����
//ѧϰʹ�ҿ��֣����ҵ�������������
//��ʦ��ʱ������������ 
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
#include<stack>//�޵�ȱʡԴ
using namespace std;
//��дתСд
void utol(string& s) {
	for(int i=0; i<s.length(); i++)
		if(isupper(s[i]))
			s[i]+=32;
	return;
}
//����
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
//������
int main() {
	string k,c;
	cin>>k>>c;
//	�ӳ���Կk
	while(k.length()<c.length())
		k.append(k);
	utol(k);
	for(int i=0; i<c.length(); i++)
		vigenere(c[i],k[i]);
	cout<<c<<endl;
	return 0;
}

