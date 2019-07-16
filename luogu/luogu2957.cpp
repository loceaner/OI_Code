#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define mod 19260817
#define ins 11111
using namespace std;

char a[90],b[90];
int la,lb;
int fa[90],ba[90];
int fb[90],bb[90];
int ans;
int maxn;

int f_insert(char s[],int len){
	ll sum=0;
	for(int i=0;i<len;i++){
		sum=(sum*ins+(ll)s[i])%mod;
	}
	return sum;
}

int b_insert(char s[],int len){
	ll sum=0;
	int lenn=strlen(s);
	for(int i=lenn-len;i<lenn;i++){
		sum=(sum*ins+(ll)s[i])%mod;
	}
	return sum;
}

int main(){
	scanf("%s",a);
	scanf("%s",b);
	la=strlen(a);
	lb=strlen(b);
	for(int i=0;i<la;i++)fa[i]=f_insert(a,i);
	for(int i=0;i<lb;i++)bb[i]=b_insert(b,i);
	for(int i=0;i<lb;i++)fb[i]=f_insert(b,i);
	for(int i=0;i<la;i++)ba[i]=b_insert(a,i);
	int minl=min(la,lb);
	ans=0;
	for(int i=0;i<minl;i++){
		if(fa[i]==bb[i]){
			ans=i;
		}
	}
	maxn=max(ans,maxn);
	ans=0;
	for(int i=0;i<minl;i++){
		if(fb[i]==ba[i]){
			ans=i;
		}
	}
	maxn=max(ans,maxn);
	cout<<maxn<<'\n';
	return 0;
}
