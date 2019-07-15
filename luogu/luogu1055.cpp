//是个牛掰的题目哦 
#include<cstdio>
using namespace std;
int sjp;
char s[11],zqlk;
int main() {
	scanf("%c-%c%c%c-%c%c%c%c%c-%c",&s[1],&s[2],&s[3],&s[4],&s[5],&s[6],&s[7],&s[8],&s[9],&s[10]);
	sjp=((s[1]-48)*1+(s[2]-48)*2+(s[3]-48)*3+(s[4]-48)*4+(s[5]-48)*5+(s[6]-48)*6+(s[7]-48)*7+(s[8]-48)*8+(s[9]-48)*9)%11;
	if (sjp<10) zqlk=sjp+48;
	else zqlk='X';
	if (zqlk==s[10]) printf("Right");
	else printf("%c-%c%c%c-%c%c%c%c%c-%c",s[1],s[2],s[3],s[4],s[5],s[6],s[7],s[8],s[9],zqlk);
	return 0;
}
