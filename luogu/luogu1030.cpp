//�������κ��������ƣ��������ܻ���Щһ��
//�ҷ����ҵ�������������У������������������......
//���Ե�ȷ�����Լ����� 
//����������һ��һ���Ǹ��ڵ�
//����.find()���� 
#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;

string s1,s2;

int chuli(int x1,int y1,int x2,int y2) {
	int m=s1.find(s2[y2]);
	cout<<s2[y2];
	if(m>x1) chuli(x1,m-1,x2,m-x1+x2-1);
	if(m<y1) chuli(m+1,y1,m-x1+x2,y2-1);
}

int main() {//s��p�������� 
	cin>>s1>>s2;
	chuli(0,s1.length()-1,0,s2.length()-1);//s��p�Ĵ����� 
	return 0;
}

