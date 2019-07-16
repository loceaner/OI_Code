#include <cstdio>
#include <vector>
#define N 50000

using namespace std;
vector<int>ans[N];
int num=0,n;
int main() {
	scanf("%d",&n);
	for(int a=1; a<=3; ++a)
		for(int b=1; b<=3; ++b)
			for(int c=1; c<=3; ++c)
				for(int d=1; d<=3; ++d)
					for(int e=1; e<=3; ++e)
						for(int f=1; f<=3; ++f)
							for(int g=1; g<=3; ++g)
								for(int h=1; h<=3; ++h)
									for(int i=1; i<=3; ++i)
										for(int j=1; j<=3; ++j)
											if(a+b+c+d+e+f+g+h+i+j==n)
												num++,ans[num].push_back(a), ans[num].push_back(b),
												    ans[num].push_back(c),ans[num].push_back(d),
												    ans[num].push_back(e),ans[num].push_back(f),
												    ans[num].push_back(g),ans[num].push_back(h),
												    ans[num].push_back(i),ans[num].push_back(j);
	printf("%d\n",num);
	for(int i=1; i<=num; ++i) {
		for(int j=0; j<ans[i].size(); ++j)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
