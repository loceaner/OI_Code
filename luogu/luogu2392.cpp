#include<bits/stdc++.h>
using namespace std;
int l,ri,minn,ans;
int s[5];
int a[21][5];
void search(int x,int y) {
	if(x>s[y]) {
		minn=min(minn,max(l,ri));
		return;
	}
	l+=a[x][y];
	search(x+1,y);
	l-=a[x][y];
	ri+=a[x][y];
	search(x+1,y);
	ri-=a[x][y];
}
int main() {
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	for(int i=1; i<=4; i++) { 
		l=ri=0;
		minn=19260817;
		for(int j=1; j<=s[i]; j++)
			cin>>a[j][i];
		search(1,i);
		ans+=minn;
	}
	cout<<ans;
	return 0;
}
