#include<iostream>
using namespace std;
int main() {
	int n,na,nb,i,x,y,p,q;
	int a[10000],b[10000];
	cin>>n>>na>>nb;
	x=0;
	y=0;
	p=0;
	q=0;
	for(i=1; i<=na; i++)
		cin>>a[i];
	for(i=1; i<=nb; i++)
		cin>>b[i];
	for(i=1; i<=n; i++) {
		p=p%na+1;
		q=q%nb+1;
		switch(a[p]) {
			case 0:
				switch(b[q]) {
					case 1:
						y++;
						break;
					case 2:
						x++;
						break;
					case 3:
						x++;
						break;
					case 4:
						y++;
						break;
				};
				break;
			case 1:
				switch(b[q]) {
					case 0:
						x++;
						break;
					case 2:
						y++;
						break;
					case 3:
						x++;
						break;
					case 4:
						y++;
						break;
				};
				break;
			case 2:
				switch(b[q]) {
					case 0:
						y++;
						break;
					case 1:
						x++;
						break;
					case 3:
						y++;
						break;
					case 4:
						x++;
						break;
				};
				break;
			case 3:
				switch(b[q]) {
					case 0:
						y++;
						break;
					case 1:
						y++;
						break;
					case 2:
						x++;
						break;
					case 4:
						x++;
						break;
				};
				break;
			case 4:
				switch(b[q]) {
					case 0:
						x++;
						break;
					case 1:
						x++;
						break;
					case 2:
						y++;
						break;
					case 3:
						y++;
						break;
				};
				break;
		}
	}
	cout<<x<<" "<<y;
}
