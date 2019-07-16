#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 100005;
int n,len;
int a[MAXN],b[MAXN];
int id[MAXN],dp[MAXN],d[MAXN];
int main() {
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        scanf("%d",&a[i]);
        id[a[i]] = i;
    }
    for(int i = 1;i <= n;i++) {
        scanf("%d",&b[i]);
    }
    int tmp;
    for(int i = 1;i <= n;i++) {
        if(id[b[i]] > d[len]) {
            d[++len] = id[b[i]];
            dp[i] = len;
            continue;
        }
        tmp = lower_bound(d + 1,d + 1 + len,id[b[i]]) - d;
        d[tmp] = id[b[i]];
        dp[i] = tmp;
    }
    printf("%d\n",len);
}
