#include <iostream>
#define INF 1000001
using namespace std;

int main() {
    int n, res = INF;
    cin >> n;
    
    int start_num = n - (n * 0.1);
    for(int i = start_num; i <= n; i++) {
        int tmp = i, sum = i;
        while(tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if(sum == n) {
            res = i;
            break;
        }
    }

    if(res == INF) cout << 0 << endl;
    else cout << res << endl;
}

/**
 * n == 1  => 1
 * n == 11 => 10 + 1
 * n == 101 => 91 + 9 + 1
 * n == 1001 => 901 + 9 + 1
 * 
 * 완전탐색 모두 하면 시간초과 날 것 같아서
 * 10% 전부터 함
 * **/