#include<bits/stdc++.h>
using namespace std;
//����㲻��stl������������±�Ϊchar����������Ϊint������ͺã�
map<char,int> a;//�������ĸ����λ����λ�г��ֵĴ���
map<char,int> total;//���������ĸ��һ���м�����λ��
char le[10];
string x,y;
int main() {
	int n,i,j;
	cin>>n;
	cin>>x;
	for(i=1; i<=n-1; i++) {
		cin>>x;
		le[i]=x[0];
	}
	for(i=1; i<=n-1; i++)
		for(j=1; j<=n; j++) {
			cin>>x;
			if(x==y&&j!=1&&j!=2) { //��Ϊ��һ���Ǽٵģ����Բ���
				cout<<"ERROR!";
				return 0;//�ж��Ƿ����ݴ���
			}
			y=x;//y������һ���ַ�
			if(x.size()==2) {
				a[x[1]]++;
				total[le[i]]++;
			}
		}
	for(i=1; i<=n-1; i++)
		if(total[le[i]]!=n-2-a[le[i]]) {
			cout<<"ERROR!";
			return 0;
		}//�������
	for(i=1; i<=n-1; i++)
		cout<<le[i]<<'='<<total[le[i]]<<' ';
	cout<<endl<<n-1;
	//
	return 0;
}
