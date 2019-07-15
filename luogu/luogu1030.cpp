//这道题与课后例题相似，做法可能会有些一样
//我发现我的做法在题解里有，但是这是例题的做法......
//所以的确是我自己做的 
//后序遍历最后一个一定是根节点
//用了.find()函数 
#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;

string s1,s2;

int chuli(int x1,int y1,int x2,int y2) {
	int m=s1.find(s2[y2]);
	cout<<s2[y2];
	if(m>x1) chuli(x1,m-1,x2,m-x1+x2-1);
	if(m<y1) chuli(m+1,y1,m-x1+x2,y2-1);
}

int main() {//s勾p的主函数 
	cin>>s1>>s2;
	chuli(0,s1.length()-1,0,s2.length()-1);//s勾p的处理函数 
	return 0;
}

