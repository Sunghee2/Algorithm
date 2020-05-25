#include <iostream>
#define MAX 1000001
using namespace std;

int N, B, C;
long long cnt = 0;
int arr[MAX];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf(" %d", &arr[i]);
    scanf("%d %d", &B, &C);

    for(int i = 0; i < N; i++) {
        arr[i] -= B;
        cnt++;
        if(arr[i] > 0) {
            cnt += arr[i] / C;
            if(arr[i] % C) cnt++;
        }
    }

    printf("%lld\n", cnt);
}