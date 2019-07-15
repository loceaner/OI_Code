#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char node[1<<(10+1)];

char give1(char u) 
{
	return u=='1' ? 'I' : 'B';
}

char give2(char u,char v) 
{
	return u==v ? u : 'F';  
}

int n;

void print(int i) 
{
	if(i>=(1<<(n+1)))
		return;
	print(i*2);
	print(i*2+1);
	putchar(node[i]);
}
int main()
{
	string s;
	cin>>n>>s;
	for(int i=0; i<s.size(); i++)
		node[(1<<n)+i]=give1(s[i]);  
	for(int i=(1<<n)-1; i; i--)
		node[i]=give2(node[i*2],node[i*2+1]);
	print(1);
	return 0;
}
