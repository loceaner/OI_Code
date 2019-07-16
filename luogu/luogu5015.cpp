#include<bits/stdc++.h>
using namespace std;

char s;
int ans=0;

int main() {
	while(scanf("%c",&s)!=EOF) {
		if(s!=' '&&s!='\n') {
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
