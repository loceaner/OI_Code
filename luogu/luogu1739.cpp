#include<bits/stdc++.h>
using namespace std;

int nok=0;
char a;
int i=0;

int main() {
	for (;; i++) {
		cin>>a;
		if(i==0&&a==')') {printf ("NO");return 0; }
		if (a=='(') nok++;
		if (a==')') nok--;
		if (nok<0) {printf ("NO");return 0;
		}
		if (a=='@') {
			if (!nok) printf ("YES");
			else printf ("NO");
			return 0;
		}
	}
}
