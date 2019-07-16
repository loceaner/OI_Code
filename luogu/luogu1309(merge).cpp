#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100011
using namespace std;

struct node {
	int num;
	int score;
} stu[N*2],a[N],b[N];

int n,r,q;
int w[2*N];

inline int read() {
	int x=0,f=1;
	char c=getchar();
	for(; !isdigit(c); c=getchar())if(c=='-')f=-1;
	for(; isdigit(c); c=getchar())x=x*10+c-48;
	return x*f;
}

bool cmp(node x,node y) {
	return x.score==y.score ? x.num<y.num : x.score>y.score;
}

void mergesort() { //¹é²¢
	int i=1,j=1,count=1;
	while(i<=n && j<=n) {
		if(a[i].score>b[j].score || (a[i].score==b[j].score&&a[i].num<b[j].num)) {
			stu[count].score=a[i].score;
			stu[count].num=a[i].num;
			count++;
			i++;
		} else {
			stu[count].score=b[j].score;
			stu[count].num=b[j].num;
			count++;
			j++;
		}
	}
	while(i<=n) {
		stu[count].score=a[i].score;
		stu[count].num=a[i].num;
		count++;
		i++;
	}
	while(j<=n) {
		stu[count].score=b[j].score;
		stu[count].num=b[j].num;
		count++;
		j++;
	}
}

int main(){
	n=read(),r=read(),q=read();
	for(int i=1;i<=2*n;i++){
		stu[i].score=read();
		stu[i].num=i;
	}
	for(int i=1;i<=2*n;i++){
		w[i]=read();
	}
	stable_sort(stu+1,stu+1+2*n,cmp);
	
	for(int j=1;j<=r;j++){
		int index=1;
		for(int i=1;i<=2*n-1;i+=2){//ÆæÊý 
			if(w[stu[i].num]>w[stu[i+1].num]){
				a[index].score=stu[i].score+1;
				a[index].num=stu[i].num;
				b[index].score=stu[i+1].score;
				b[index].num=stu[i+1].num;
				index++;
			}
			else{
				a[index].score=stu[i+1].score+1;
				a[index].num=stu[i+1].num;
				b[index].score=stu[i].score;
				b[index].num=stu[i].num;
				index++;
			}
		}
		mergesort();
	}
	cout<<stu[q].num<<'\n';
	return 0;
}
