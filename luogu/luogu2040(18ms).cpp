#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main();
int i,j,ans=10005,a[4][4],dx[4]= {0,1,0,-1},dy[4]= {1,0,-1,0}; //�ĸ�����
bool judge(void) { //�ж��Ƿ�ȫ��
	for(int i=1; i<=3; i++)
		for(int j=1; j<=3; j++)
			if(!a[i][j]) return false;
	return true;
}
void change(int x,int y) { //�ı�һ���㼰����Χ���״̬
	a[x][y]^=1;
	for(int i=0; i<4; i++) {
		int xx=x+dx[i],yy=y+dy[i];
		a[xx][yy]^=1;
	}
}
void search(int x,int y,int tot) {
	if(judge()) ans=min(ans,tot);//���´�
	if(y>3) { //��һ��
		search(x+1,1,tot);
		return;
	}
	if(x>3) return ;//��������
	change(x,y);//�ı䵱ǰ���״̬
	search(x,y+1,tot+1);//��+1����һ����
	change(x,y);//����
	search(x,y+1,tot);//���ı�������״̬
}
int main() {
	for(i=1; i<=3; i++)
		for(j=1; j<=3; j++)
			scanf("%d",&a[i][j]);
	search(1,1,0);//��1��1�㿪ʼ����
	printf("%d",ans);
	return 0;
}
