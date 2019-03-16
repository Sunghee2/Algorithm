#include <iostream>
using namespace std;

int main() {
    int testcase, n, m, cost;
    cin >> testcase;

    for(int i = 1; i <= testcase; i++) {
        cin >> n >> m;
        int interest[1001];
        int vote[1001] = { 0 };
        for(int j = 1; j <= n; j++) {
            cin >> interest[j];
        }

        for(int j = 0; j < m; j++) {
            cin >> cost;
            for(int k = 1; k <= n; k++) {
                if(interest[k] <= cost) {
                    vote[k]++;
                    break;
                }
            }
        }

        int max = 0;
        int max_index = 0;
        for(int j = 1; j <= n; j++) {
            if(max < vote[j]) {
                max = vote[j];
                max_index = j;
            }
        }

        printf("#%d %d\n", i, max_index);
    }
}

/**
 * 각 위원이 생각하는 비용을 입력받아 
 * 종목배열(interest) 루트를 돌면서 해당 비용보다 작거나 같은 경우가 나오면
 * vote배열에서 해당 종목 인덱스에 1을 더해주고 브레이크
 * 그리고 vote배열 중에 max값을 가지는 index를 출력해주면 됨
 * **/