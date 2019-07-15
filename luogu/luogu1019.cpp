#include<iostream>
using namespace std;
int n,used[20]= {0},maxn=0;
string s[20],sum,x;
void dfs(string last) {
	if(last.size()==1) sum=last;
	bool ans=0;
	for(int i=0; i<n; i++) {
		if(used[i]<2) {
			int m;
			for(int j=last.size()-1; j>=0; j--) {
				if(last[j]==s[i][0]) {
					m=1;
					ans=1;
					while(last[j+m]==s[i][m]) m++;
				}
				if(ans&&j+m==last.size()) break;
				if(ans&&j+m!=last.size()) ans=0;
			}
			if(ans) {
				int len=sum.size();
				sum+=s[i].substr(m,s[i].size()-m);
				used[i]++;
				dfs(s[i]);
				ans=0;
				used[i]--;
				sum.erase(len,s[i].size()-m);
			}
		}
	}
	if(!ans&&sum.size()>maxn) maxn=sum.size();
	return;
}
int main() {
	cin>>n;
	for(int i=0; i<n; i++) cin>>s[i];
	cin>>x;
	dfs(x);
	cout<<maxn;
	return 0;
}
