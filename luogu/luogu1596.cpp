#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<deque>
using namespace std;

int n,m;
char a[101][101];
bool f[101][101]= {false};

int baosou(int x,int y) {//�����ʵ����ˮ��ɾ��
	if(a[x][y+1]=='W') {
		a[x][y+1]='.';
		baosou(x,y+1);
	}
	if(a[x][y-1]=='W'){
		a[x][y-1]='.';
		baosou(x,y-1);
	}
	if(a[x+1][y]=='W') {
		a[x+1][y]='.';
		baosou(x+1,y);
	}
	if(a[x-1][y]=='W') {
		a[x-1][y]='.';
		baosou(x-1,y);
	}
	if(a[x+1][y+1]=='W') {
		a[x+1][y+1]='.';
		baosou(x+1,y+1);
	}
	if(a[x+1][y-1]=='W') {
		a[x+1][y-1]='.';
		baosou(x+1,y-1);
	}
	if(a[x-1][y+1]=='W') {
		a[x-1][y+1]='.';
		baosou(x-1,y+1);
	}
	if(a[x-1][y-1]=='W') {
		a[x-1][y-1]='.';
		baosou(x-1,y-1);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	if(m==0)return 0;
	int ans=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>a[i][j];
            //���ҵģ���Զ��Ҫ��scanf�����ַ�
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(a[i][j]=='W') {
				a[i][j]='.';
				ans++;//�ҵ�֮�������
				baosou(i,j);//��ʼ����
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
