#include<bits/stdc++.h>
using namespace std;

struct tkj {
	int a[3];
} h[50000+5];

bool point[50005];

int main() {
	int n;
	scanf("%d",&n);
	for(int i=0; i<n-2; ++i)
		for(int j=0; j<3; j++)
			scanf("%d",&h[i].a[j]);
	for(int j=0; j<3; ++j)
		point[h[0].a[j]]=true;
	short ans=0;
	for(int i=1; i<=n-3; ++i) {
		int ans2=0;
		for(int j=0; j<3; ++j)
			ans2+=point[h[i].a[j]];
		if(ans2==2) ++ans;
	}
	if(ans==1)  printf("JMcat Win");
	else if(ans==2) {
		if(n%2) printf("PZ Win");
		else printf("JMcat Win");
	} else {
		if(n%2) printf("PZ Win");
		else printf("JMcat Win");
	}
	return 0;
}
