#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;


int main() {
    int testcase, n, k;
    int arr[100001];
    scanf("%d", &testcase);
    for(int tc = 1; tc <= testcase; tc++) {
        scanf("%d %d", &n, &k);
        double ans = 0;
        for(int i = 0; i < n; i++) {
            scanf(" %d", &arr[i]);
        }
        
        sort(arr, arr + n, greater<int>());
        for(int i = k - 1; i >= 0; i--) {
            ans = (ans + arr[i]) / 2.0;
        }
        printf("#%d %f\n", tc, ans);
    }
}