#include<bits/stdc++.h>
using namespace std;
const int N = 31000;
int n,m,ans=0;
bool u[N]= {0};
struct Edge {
	int x,y,z;
} a[N];
bool cmp(Edge a,Edge b) {
	return a.y<b.y;
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=m; i++)
		cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+m+1,cmp);
	for(int i=1; i<=m; i++) {
		int sum=0;
		for(int j=a[i].x; j<=a[i].y; j++)
			if(u[j]) sum++;//ͳ�����е�����
		if(sum>=a[i].z) continue;//����ͼ���
		for(int k=a[i].y; k>=a[i].x; k--) { //���������
			if(!u[k]) {
				u[k]=1;
				sum++;
				ans++;//��++
				if(sum==a[i].z) break;//ֱ�����㣬�˳�
			}
		}
	}
	cout<<ans;//������𰸣������ٵ�����������
	return 0;
}
