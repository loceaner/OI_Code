#include<bits/stdc++.h>
using namespace std;
//如果你不会stl，把这个理解成下标为char，储存类型为int的数组就好；
map<char,int> a;//储存该字母在两位数个位中出现的次数
map<char,int> total;//储存这个字母这一行有几个两位数
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
			if(x==y&&j!=1&&j!=2) { //以为第一列是假的，所以不管
				cout<<"ERROR!";
				return 0;//判断是否数据错误
			}
			y=x;//y储存上一个字符
			if(x.size()==2) {
				a[x[1]]++;
				total[le[i]]++;
			}
		}
	for(i=1; i<=n-1; i++)
		if(total[le[i]]!=n-2-a[le[i]]) {
			cout<<"ERROR!";
			return 0;
		}//计算错误
	for(i=1; i<=n-1; i++)
		cout<<le[i]<<'='<<total[le[i]]<<' ';
	cout<<endl<<n-1;
	//
	return 0;
}
