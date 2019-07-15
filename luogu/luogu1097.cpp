#include<string>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,ans=1;
int a[200005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1])ans++;
        else{
            cout<<a[i-1]<<' '<<ans<<endl;
            ans=1;
        }
    }
    cout<<a[n]<<' '<<ans<<endl;
    return 0;
}
