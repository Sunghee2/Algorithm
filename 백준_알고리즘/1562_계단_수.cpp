#include <iostream>
#include <cstring>
using namespace std;

int n, ans;
long long arr[101][10];

int countNumber() {
    arr[10][0] = 1; 
    arr[10][9] = 1;
    for(int i = 11; i <= n; i++) {
        for(int j = 0; j < 10; j++) {
            if(arr[i - 1][j] > 0) {
                if(j - 1 >= 0) arr[i][j - 1] += (arr[i - 1][j] % 1000000000);
                if(j + 1 <= 9) arr[i][j + 1] += (arr[i - 1][j] % 1000000000); 
            }
        }
    }

    long long sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += (arr[n][i] % 1000000000);
    }

    return sum;
}

int main() {
    cin >> n;
    // long long sum = 0;
    // for(int i = 1; i <= 40; i++ ) {
    //     n = i;
    //     memset(arr, 0, sizeof(arr));
        if(n < 10) ans = 0;
        else if(n == 10) ans = 1;
        else ans = countNumber();

    //     cout << "n : " << n << " ans : " << ans << endl;

    //     sum += ans;
    // }   

    cout << (ans % 1000000000) << endl;
    // cout << sum << endl;
}