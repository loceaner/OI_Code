#include<iostream>
using namespace std;
int n,st,sp;
char c[101];
void print() {                                //��ӡ
	int i;
	for (i=1; i<=2*n+2; i++) cout<<c[i];
	cout<<endl;
	st++;
}
void init(int n) {                           //��ʼ��
	int i;
	st=0;
	sp=2*n+1;
	for (i=1; i<=n; i++) c[i]='o';
	for (i=n+1; i<=2*n; i++) c[i]='*';
	c[2*n+1]='-';
	c[2*n+2]='-';
	print();
}
void move(int k) {                          //�ƶ�һ��
	int j;
	for (j=0; j<=1; j++) {
		c[sp+j]=c[k+j];
		c[k+j]='-';
	}
	sp=k;
	print();
}
void mv(int n) {                                     //��Ҫ����
	int i,k;
	if (n==4) {              //n����4�����Ҫ���⴦��
		move(4);
		move(8);
		move(2);
		move(7);
		move(1);
	} else {
		move(n);
		move(2*n-1);
		mv(n-1);
	}
}
int main() {
	cin>>n;
	init(n);
	mv(n);
}

