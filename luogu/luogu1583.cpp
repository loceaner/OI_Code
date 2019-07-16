#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct student {
	int number;// 编号
	int W;// 初始权值
	int D;// 序号
	int E;// 额外的权值
	int total;// 总权值
};
int n,k;
int e[15];//额外权值(由类别序号决定)
int d[20010];//每个人的序号
int w;//初始权值
vector<student>stu;
//根据初始权值，由大到小排序。若初始权值相同，则编号小的优先
bool cmp1(student x,student y) {
	if(x.W>y.W)return true;
	else {
		if(x.W==y.W) {
			if(x.number<y.number)return true;
			else return false;
		} else return false;
	}
}
//根据总权值，由大到小排序。若总权值相同，则编号小的优先
bool cmp2(student x,student y) {
	if(x.total>y.total)return true;
	else {
		if(x.total==y.total) { //【坑点】未加上，仅过两个测试；加上则AC
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
	sort(stu.begin(),stu.end(),cmp1);//根据初始权值排序
	for(int i=0; i<stu.size(); i++) {
		stu[i].D=i+1;//序号
		stu[i].E=e[i%10+1];// i%10+1为类别序号的值；根据类别序号决定额外权值
		stu[i].total=stu[i].W+stu[i].E;//总权值
	}
	sort(stu.begin(),stu.end(),cmp2);//根据总权值排序
	//输出前k个人
	for(int i=0; i<k-1; i++) {
		printf("%d ",stu[i].number);
	}
	printf("%d\n",stu[k-1].number);
	return 0;
}
