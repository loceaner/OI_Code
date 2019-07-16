#include<bits/stdc++.h>
using namespace std;

struct node {
	int sx,sy;
};
int s1[3],s2[3];
node head;
int dx[12]= {1,2,2,2,2,1,-1,-2,-2,-2,-2,-1};
int dy[12]= {2,2,1,-1,-2,-2,-2,-2,-1,1,2,2};
int a[1010][1010];
queue<node> q;

int main() {
	for(int i=1; i<=2; i++) {
		cin>>s1[i]>>s2[i];
	}
	for(int k=1; k<=2; k++) {
		memset(a,0,sizeof(a));
		q.push((node) {s1[k],s2[k]});
		a[s1[k]][s2[k]]=0;
		while(!q.empty()) {
			head=q.front();
			q.pop();
			int xx=head.sx;
			int yy=head.sy;
			for(int i=0; i<12; i++) {
				int nx=xx+dx[i];
				int ny=yy+dy[i];
				if(a[nx][ny]==0&&nx>0&&ny>0&&nx<=99&&ny<=99) {
       				a[nx][ny]=a[xx][yy]+1;
       				q.push((node){nx,ny});
				}
			}
		}
		cout<<a[1][1]<<'\n';
	}
	return 0;
}
