//    ����һ���ܼ򵥵�̰���⡣
//
//����i��ʾ��i���ƶѣ�ÿ�ζ���֤i�ƶ��ǵ���ƽ��ֽ��
//
//������Ϊ���������٣���ô�϶�Ҫ�ӱ���ƶѽ�(��������һ������ʱ����)��
//
//��������ƶ࣬�϶�Ҫ��ȥ����ƶѡ�
//
//������ô���ǵ�ǰֻ���Ǹ��ƶѵ����Ƿ����ƽ��ֽ��(̰��)
//
//����������࣬����ȥ��һ���ƶѣ�����پʹ���һ���ƶѽ�(��һ���ƶѱ�ʾmdzz)��
//
//��������Ū��ȥ����֤��1��n-1���ƶ��ǵ���ƽ����������ô��n����Ҳ����ƽ��������
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	int n, a[105], sum, ans;
	sum = ans = 0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {  //��i���ƣ���1��ʼ��n
		scanf("%d", a+i);
		sum += a[i];
	}
	sum /= n;                //����ƽ������
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