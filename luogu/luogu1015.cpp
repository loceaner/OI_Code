//s��p����ר�����
//ѧϰʹ�ҿ��֣����ҵ�������������
#include<iostream>//�Һ��ڿ죬д��ͷ�ļ��ر�� 
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<iomanip>
//��ʵ�һ���д 
using namespace std;

long long n=0,m,l,e;
string str;

bool sjp(long long a) {//�ҵ�sjp���� 
	long long s=0;
	for (long long i=a; i; i/=m)
		s=s*m+i%m;
	e=s+a;
	return s==a;
}

long long ch(char a) {
	if ((a>='0')&&(a<='9'))//�����־ͷ��� 
		return a-'0';
	return a-'A'+10;
}

int main() {
	cin>>m>>str;
	l=str.size();
	for (int i=0; i<l; i++)
		n=n*m+ch(str[i]);
	long long bu;
	for (bu=0; !sjp(n) && bu<=30; bu++)
		n=e;
	if (bu<=30) cout<<"STEP="<<bu<<endl;
	else cout<<"Impossible!";//������ 
	return 0;
}

