#include <iostream>
using namespace std;

int main() {
    int find_num, cnt = 0;
    scanf("%d", &find_num);

    int arr[5];
    scanf("%d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);

    for(int i = 0; i < 5; i++) {
        if(arr[i] == find_num) cnt++;
    }

    printf("%d\n", cnt);
}