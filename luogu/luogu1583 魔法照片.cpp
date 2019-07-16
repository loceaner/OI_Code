#include<cstdio>
#include<algorithm>
using namespace std;
struct Person {
	int id,w;
} 
p[10000001]; 
int n,k,E[11];
bool cmp(Person,Person); 
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1; i<=10; i++) scanf("%d",&E[i]);
	for(int i=0; i<n; i++) {
		scanf("%d",&p[i].w);
		p[i].id=i+1;
	}
	sort(p,p+n,cmp); 
	for(int i=0; i<n; i++)
		p[i].w+=E[i%10+1];
	sort(p,p+n,cmp);
	for(int i=0; i<k; i++) printf("%d ",p[i].id);
	return 0;
}
bool cmp(Person a,Person b) {
	if(a.w==b.w)
		return a.id<b.id;
	return a.w>b.w;
}
