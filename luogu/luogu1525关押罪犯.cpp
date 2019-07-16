#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,fa[40004];
struct T {
    int a,b,w;
} e[100001];

bool cmp(T o,T u) {
    return o.w>u.w;
}
int find(int x) {
    if(x!=fa[x]) return fa[x]=find(fa[x]);
    return fa[x];
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n*2; ++i)
        fa[i]=i;
    for(int i=1; i<=m; ++i)
        scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].w);
    sort(e+1,e+1+m,cmp);
    int a,b;
    for(int i=1; i<=m; ++i) {
        a=find(e[i].a),b=find(e[i].b);
        if(a==b) {
            printf("%d",e[i].w);
            return 0;
        }
        fa[a]=find(e[i].b+n);
        fa[b]=find(e[i].a+n);
    }
    printf("0");
    return 0;
}
