#include<bits/stdc++.h>
using namespace std;
string st[1001],s[1001];
int f[8]={0,-1,-1,-1,0,1,1,1};
int g[8]={1,1,0,-1,-1,-1,0,1};
int a1,a2,n;
bool pd;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			st[i]+='0';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-1;j++){
			if(s[i][j]=='y'){
				for(int k=0;k<=7;k++){
					a1=i;a2=j;
					pd=1;
					for(int l=1;l<=6;l++){
						a1+=f[k];a2+=g[k];
						if(a1<1||a1>n||a2<0||a2>n-1)pd=0;
						if(pd==0)break;
						if(l==1&&s[a1][a2]!='i')pd=0;
						if(l==2&&s[a1][a2]!='z')pd=0;
						if(l==3&&s[a1][a2]!='h')pd=0;
						if(l==4&&s[a1][a2]!='o')pd=0;
						if(l==5&&s[a1][a2]!='n')pd=0;
						if(l==6&&s[a1][a2]!='g')pd=0;						
					}
					a1=i;a2=j;
					if(pd){
						for(int l=0;l<=6;l++){
							st[a1][a2]=s[a1][a2];
							a1+=f[k],a2+=g[k];
						}
					}
				}
			}
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-1;j++){
			if(st[i][j]=='0')st[i][j]='*';
		}
	}
	for(int i=1;i<=n;i++){
		cout<<st[i]<<'\n';
	}
}
