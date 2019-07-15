#include<stdio.h>
long  long B[21][21];
int main(void) {
	int i,j,n,m,a,b;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(i=0; i<=n; i++)
		for(j=0; j<=m; j++)
			B[i][j]=1;
	if(a-2>=0&&b-1>=0)
		B[a-2][b-1]=0;
	if(a-2>=0&&b+1<=m)
		B[a-2][b+1]=0;
	if(a-1>=0&&b-2>=0)
		B[a-1][b-2]=0;
	if(a-1>=0&&b+2<=m)
		B[a-1][b+2]=0;
	if(a+1<=m&&b-2>=0)
		B[a+1][b-2]=0;
	if(a+2<=n&&b-1>=0)
		B[a+2][b-1]=0;
	if(a+1<=n&&b+2<=m)
		B[a+1][b+2]=0;
	if(a+1<=n&&b+1<=m)
		B[a+2][b+1]=0;
	B[a][b]=0;
	for(i=0; i<=n; i++) {
		for(j=0; j<=m; j++) {
			if(B[i][j]) {
				if(i==0&&j==0) continue;
				else  if(i==0)  B[i][j]=B[i][j-1];
				else if(j==0)   B[i][j]=B[i-1][j];
				else B[i][j]=B[i-1][j]+B[i][j-1];
			}
		}
	}
	printf("%lld",B[n][m]);                /*第一次是用int  后来发现有点小改成long long  之后一直错  上网查了一下下午终于在下午五点发现输出居然用%d！！！ 这道题略坑，我早上11点做到17:55..只是因为这样一个错误。百密一疏呀。*/
	return 0;
}

