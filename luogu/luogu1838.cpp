#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int vis[4][4];//ģ������
char s[10];//����
int main() {
	scanf("%s",s+1);//�����ַ���
	int len=strlen(s+1);
	int flag=1;
	for(int i=1; i<=len; i++) {
		flag=-flag;//ÿ�ν�flag����෴�����������ִ����
		if(s[i]=='1')
			vis[1][1]=flag;
		if(s[i]=='2')
			vis[1][2]=flag;
		if(s[i]=='3')
			vis[1][3]=flag;
		if(s[i]=='4')
			vis[2][1]=flag;
		if(s[i]=='5')
			vis[2][2]=flag;
		if(s[i]=='6')
			vis[2][3]=flag;
		if(s[i]=='7')
			vis[3][1]=flag;
		if(s[i]=='8')
			vis[3][2]=flag;
		if(s[i]=='9')
			vis[3][3]=flag;
	}
	if((vis[1][1]==1&&vis[1][2]==1&&vis[1][3]==1)||(vis[2][1]==1&&vis[2][2]==1&&vis[2][3]==1)||(vis[3][1]==1&&vis[3][2]==1&&vis[3][3]==1)||(vis[3][3]==1&&vis[1][1]==1&&vis[2][2]==1)||(vis[3][1]==1&&vis[2][2]==1&&vis[1][3]==1)||(vis[1][1]==1&&vis[2][1]==1&&vis[3][1]==1)||(vis[1][1]==1&&vis[1][2]==1&&vis[1][3]==1)||(vis[1][2]==1&&vis[2][2]==1&&vis[3][2]==1)||(vis[1][3]==1&&vis[2][3]==1&&vis[3][3]==1))//ö��8�����
		printf("uim wins.");
	else if((vis[1][1]==-1&&vis[1][2]==-1&&vis[1][3]==-1)||(vis[2][1]==-1&&vis[2][2]==-1&&vis[2][3]==-1)||(vis[3][1]==-1&&vis[3][2]==-1&&vis[3][3]==-1)||(vis[3][3]==-1&&vis[1][1]==-1&&vis[2][2]==-1)||(vis[3][1]==-1&&vis[2][2]==-1&&vis[1][3]==-1)||(vis[1][1]==-1&&vis[2][1]==-1&&vis[3][1]==-1)||(vis[1][1]==-1&&vis[1][2]==-1&&vis[1][3]==-1)||(vis[1][2]==-1&&vis[2][2]==-1&&vis[3][2]==-1)||(vis[1][3]==-1&&vis[2][3]==-1&&vis[3][3]==-1))////ö��8�����
		printf("xiaoa wins.");
	else printf("drew.");
}
