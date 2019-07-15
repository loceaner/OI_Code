//    这是一道很简单的贪心题。
//
//　　i表示第i个牌堆，每次都保证i牌堆是等于平均纸牌
//
//　　因为如果这堆牌少，那么肯定要从别的牌堆借(可以让下一堆牌暂时负数)，
//
//　　这堆牌多，肯定要扔去别的牌堆。
//
//　　那么我们当前只考虑该牌堆的牌是否等于平均纸牌(贪心)
//
//　　如果多余，就扔去下一个牌堆，如果少就从下一个牌堆借(下一个牌堆表示mdzz)。
//
//　　这样弄下去，保证了1到n-1的牌堆是等于平均牌数，那么第n堆牌也等于平均牌数。
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	int n, a[105], sum, ans;
	sum = ans = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {  //第i堆牌，从1开始到n
		scanf("%d", a+i);
		sum += a[i];
	}
	sum /= n;                //计算平均牌数
	for(int i=1; i<=n; i++) {
		if(a[i] != sum) {
			if(a[i] > sum ){
			a[i+1] += a[i] - sum;
				a[i] = sum;
				ans++;
			} else {
				a[i+1] -=  sum - a[i];
				a[i] = sum;
				ans++;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
