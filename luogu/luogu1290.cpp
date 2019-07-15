#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int n,x,y,ans;
int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void f(int x,int y)
{
    while(1)
    {
        if(x>y) swap(x,y);
        if(y%x==0) break;
        if(y-x>x) break;
        y-=x;
        ans++;
    }
}
int main()
{
    n=read();
    while(n--)
    {
        ans=0;
        x=read(),y=read();
        f(x,y);
        if(ans%2==0) printf("Stan wins\n");
        else printf("Ollie wins\n");
    }
    return 0;
}
