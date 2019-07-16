#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
priority_queue<string,vector<string>,greater<string> >qaq;
queue<string>qwq2;
int main() {
	ios::sync_with_stdio(false);
	int n;
	string input,t;
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>input;
		qwq2.push(input);
	}
	cin>>t;
	while (!qwq2.empty()) {
		input=qwq2.front();
		qwq2.pop();
		if (input.find(t,0)==0) {
			qaq.push(input);
		}
	}
	while (!qaq.empty()) {
		input=qaq.top();
		qaq.pop();
		if (!qaq.empty()) {
			cout<<input<<endl;
		} else {
			cout<<input;
		}
	}
	return 0;
}
