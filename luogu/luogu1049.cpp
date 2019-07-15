#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 35;

int v; //���ӵ�����
int n; //��Ʒ�ĸ���
int w[N]; //��Ʒ���Ե����
int dp[20005]; 

int main() {
    scanf("%d", &v);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", &w[i]);
    for (int i = 1; i <= n; ++i) {
        for (int j = v; j >= 0; --j) {
            if (j >= w[i])  
                dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
        }
    }
    printf("%d\n", v - dp[v]);
    return 0;
}
