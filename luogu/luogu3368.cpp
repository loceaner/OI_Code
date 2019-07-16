#include <iostream>
using namespace std;

#define LBS(_a) ((_a) & -(_a))
#define SIZE 5000005

int n, m;
int arr[SIZE];

int sum(int i) {
    int sum = 0;
    while (i > 0) {
        sum += arr[i], i -= LBS(i);
    }
    return sum;
}

void add(int i, int value) {
    while (i <= n) {
        arr[i] += value, i += LBS(i);
    }
    return ;
}

int main() {
    cin >> n >> m;
    int val, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        ans = val - ans;
        add(i, ans);
        ans = val;
    }
    int x, y, z, s;
    while (m > 0) {
        cin >> x ; 
        if (x == 1) {
            cin >> y >> z >> s;
            add(y, s);
            add(z + 1, -s); // [y, z] Ö»¸Ä±äarr[y], arr[z+1]
        }
        if (x == 2) {
            cin >> s;
            cout << sum(s) << endl;
        }
        m -= 1;    
    } 
    return 0;
}
