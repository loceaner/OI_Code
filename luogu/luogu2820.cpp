#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#define maxn 1010
using namespace std;

int n,m;
long long sum=0;//������С������Ȩֵ֮��
long long ans=0;//this is answer
int g[maxn][maxn], minn[maxn];
//g���������ڽӾ���洢��minn����洢��СȨֵ
bool u[maxn];//�ж��Ƿ��Ѽ�����С������

int main() {
	//���Ѿ�������memset��ֵ��ά�����ˣ�̫��ѧ��
	memset(g,0x7f,sizeof(g));
	memset(minn,0x7f,sizeof(minn));//��ʼΪ���ֵ
	memset(u,true,sizeof(u));//��ʼ��ȫΪ����
	//ǰ��Ķ��ǳ�ʼ��qwq
	minn[1]=0;//���Ǵӵ�һ���㿪ʼ�������Լ����Լ��ľ���Ϊ0
	scanf("%d%d",&n,&m);
	int x,y,w;
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&x,&y,&w);
		g[x][y]=g[y][x]=w;
		//��ʾx��y����֮����һ��ȨֵΪw�ı�
		ans+=w;//����׼��������ٺ�
	}
	//Prim�㷨
	for(int i=1; i<=n; i++) {
		int k=0;
		for(int j=1; j<=n; j++) {
			if(u[j] && minn[k]>minn[j]) {
				k=j;
			}
		}
		u[k]=false;//��������С�������ͱ�Ϊ�׵�
		for(int j=1; j<=n; j++) {
			if(u[j] && minn[j]>g[k][j]) {
				minn[j]=g[k][j];
			}
		}
	}
	for(int i=1; i<=n; i++) {
		sum+=minn[i];
	}
	ans-=sum;//���
	cout<<ans<<'\n';
	return 0;
}
