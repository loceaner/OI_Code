#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;

int stack[1001];
char s[1001];

int comp(char s[1001]) {
	int i=0,top=0,x,y;
	while(i<=strlen(s)-2) {
		switch(s[i]) {
			case '+':stack[--top]+=stack[top+1];break;
			case '-':stack[--top]-=stack[top+1];break;
			case '*':stack[--top]*=stack[top+1];break;
			case '/':stack[--top]/=stack[top+1];break;
			default:x=0;while (s[i]!='.') x=x*10+s[i++]-'0';stack[++top]=x;break;
		}
		i++;
	}
	return stack[top];
}

int main()
{
	gets(s);
	printf("%d",comp(s));
	return 0;
}
