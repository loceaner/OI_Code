//s��p����ר�����
//ѧϰʹ�ҿ��֣����ҵ�������������
#include<bits/stdc++.h>//s��p����������ͷ 
using namespace std;
char x;
long long coe,value,vivo=1;//vivo x27 ��� 
double ans;
int main() {//s��p����������~~ 
	char c=getchar();
	long long r=0,s=1;
	bool ten=false;
	while (true) {
		if (c>='a' && c<='z') {
			x=c;
			if (r==0 && !ten) coe+=vivo*s,ten=false;
			else coe+=vivo*s*r,r=0,s=1,ten=false;
		} else if (c=='-') value+=-vivo*s*r,r=0,s=-1,ten=false;
		else if (c=='+') value+=-vivo*s*r,r=0,s=1,ten=false;
		else if (c>='0' && c<='9') r=r*10+c-'0',ten=true;
		else if (c=='=') value+=-vivo*s*r,r=0,s=1,vivo=-vivo,ten=false;
		else {
			value+=-vivo*s*r;
			break;
		}
		c=getchar();
	}
	ans=double(value)/coe;
	printf("%c=%.3lf",x,ans==0?abs(ans):ans);
	return 0;
}
