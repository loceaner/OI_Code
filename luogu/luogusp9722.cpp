//�����ù鲢������Լ��ɣ��Լ���Ĵ���
//��Ҫ����Ϊʲôÿ�ζ�˵�Լ���ģ�������Ϊ����������˵������
//���ǹ��Ƚ䱸��лл��� 
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int n,m;
int ans=0;
int a[5000007],b[5000007];

void sort(int l,int r) {//�Լ���Ĺ鲢���� 
	if(l==r)return;
	int m=(l+r)>>1;
	sort(l,m);
	sort(m+1,r);
	int i=l,j=m+1,k=l;
	while(i<=m&&j<=r) {
		if(a[i]<=a[j])b[k++]=a[i++];
		else ans+=m-i+1,b[k++]=a[j++];
	}
	while(i<=m)b[k++]=a[i++];
	while(j<=r)b[k++]=a[j++];
	for(i=l; i<=r; ++i)a[i]=b[i];
}

int main() {//�Լ���������� 
	cin>>n;
	for(int i=1; i<=n; i++) {
		ans=0; 
		cin>>m;
		for(int j=1; j<=m; j++) {
			scanf("%d",&a[j]);
		}
		sort(1,m);
		printf("%d\n",ans);
	}
	return 0;
}
