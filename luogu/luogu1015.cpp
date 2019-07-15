//s勾p防盗专用语句
//学习使我快乐，让我的人生更加美好
#include<iostream>//我很勤快，写的头文件特别多 
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<iomanip>
//其实我还能写 
using namespace std;

long long n=0,m,l,e;
string str;

bool sjp(long long a) {//我的sjp函数 
	long long s=0;
	for (long long i=a; i; i/=m)
		s=s*m+i%m;
	e=s+a;
	return s==a;
}

long long ch(char a) {
	if ((a>='0')&&(a<='9'))//是数字就返回 
		return a-'0';
	return a-'A'+10;
}

int main() {
	cin>>m>>str;
	l=str.size();
	for (int i=0; i<l; i++)
		n=n*m+ch(str[i]);
	long long bu;
	for (bu=0; !sjp(n) && bu<=30; bu++)
		n=e;
	if (bu<=30) cout<<"STEP="<<bu<<endl;
	else cout<<"Impossible!";//愉快输出 
	return 0;
}

