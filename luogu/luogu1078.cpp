#include<bits/stdc++.h>
using namespace std;
int n,k,m,s,t,c[120],g[120][120],f[120][120],a,b,l;
int main() {
	cin>>n>>k>>m>>s>>t;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			f[i][j]=21743822;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	for(int i=1; i<=k; i++) {
		for(int j=1; j<=k; j++) {
			cin>>g[i][j];
		}
	}
	for(int i=1; i<=m; i++) {
		cin>>a>>b>>l;
		if(!g[c[b]][c[a]]&&c[b]!=c[a])f[a][b]=min(f[a][b],l);
		if(!g[c[a]][c[b]]&&c[b]!=c[a])f[b][a]=min(f[b][a],l);
	}
	if(c[s]==c[t]) {
		cout<<-1;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i!=j)
				for(int k=1; k<=n; k++) {
					if(j!=k&&i!=k) {
						if(f[i][k]+f[k][j]<f[i][j]) {
							f[i][j]=f[i][k]+f[k][j];
						}
					}
				}
		}
	}
	if(f[s][t]==21743822)cout<<-1;
	else cout<<f[s][t];
}
