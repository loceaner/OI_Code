#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct student {
	int number;// ���
	int W;// ��ʼȨֵ
	int D;// ���
	int E;// �����Ȩֵ
	int total;// ��Ȩֵ
};
int n,k;
int e[15];//����Ȩֵ(�������ž���)
int d[20010];//ÿ���˵����
int w;//��ʼȨֵ
vector<student>stu;
//���ݳ�ʼȨֵ���ɴ�С��������ʼȨֵ��ͬ������С������
bool cmp1(student x,student y) {
	if(x.W>y.W)return true;
	else {
		if(x.W==y.W) {
			if(x.number<y.number)return true;
			else return false;
		} else return false;
	}
}
//������Ȩֵ���ɴ�С��������Ȩֵ��ͬ������С������
bool cmp2(student x,student y) {
	if(x.total>y.total)return true;
	else {
		if(x.total==y.total) { //���ӵ㡿δ���ϣ������������ԣ�������AC
			if(x.number<y.number)return true;
			else return false;
		} else return false;
	}
}

int main() {
	scanf("%d%d",&n,&k);
	for(int i=1; i<=10; i++) {
		scanf("%d",&e[i]);
	}
	student temp;
	for(int i=1; i<=n; i++) {
		scanf("%d",&w);
		temp.number=i;
		temp.W=w;
		stu.push_back(temp);
	}
	sort(stu.begin(),stu.end(),cmp1);//���ݳ�ʼȨֵ����
	for(int i=0; i<stu.size(); i++) {
		stu[i].D=i+1;//���
		stu[i].E=e[i%10+1];// i%10+1Ϊ�����ŵ�ֵ�����������ž�������Ȩֵ
		stu[i].total=stu[i].W+stu[i].E;//��Ȩֵ
	}
	sort(stu.begin(),stu.end(),cmp2);//������Ȩֵ����
	//���ǰk����
	for(int i=0; i<k-1; i++) {
		printf("%d ",stu[i].number);
	}
	printf("%d\n",stu[k-1].number);
	return 0;
}
