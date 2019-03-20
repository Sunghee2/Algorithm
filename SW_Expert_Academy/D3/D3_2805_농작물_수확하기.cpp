#include <iostream>
#include <string>
using namespace std;

int main() {
    int testcase, size;
    scanf("%d", &testcase);
    
    for(int i = 1; i <= testcase; i++) {
        scanf("%d", &size);
        string arr_value[size];
        int sum = 0;

        for(int j = 0; j < size; j++) {
            cin >> arr_value[j];
        }

        for(int j = 0; j < size / 2; j++) {
            int index = (size - (j + j + 1)) / 2;
            for(int k = index; k < size - index; k++) {
                sum += arr_value[j].at(k) - '0'; // 위에서부터
                sum += arr_value[size - 1 - j].at(k) - '0'; // 아래서부터
            }
        }
    
        // 한 줄의 모든 칸 숫자가 더해지는 줄 ex) 3x3에서 1번째 행(0부터 시작)
        for(int j = 0; j < size; j++) {
            sum += arr_value[(size - 1) / 2].at(j) - '0';
        }

        printf("#%d %d\n", i, sum);
    }
}

/**
 * string으로 받아서 at으로 접근하는 방식 사용.
 * 테케에서 첫 번째 행을 보면 들어가야하는 숫자는 0으로
 * size에서 1을 빼고 난 4에서 2를 나누면 0이 있는 index(3)가 됨.
 * 두 번째 행에서도
 * size에서 3을 빼고 난 2에서 2를 나누면 4가 있는 index(1)가 됨.
 * 이 두 번째 행에서는 4 + 2 + 5를 더해야 하는데 5는 size-index-1하면 접근할 수 있음.
 * 첫 번째 행은 마지막 행이랑 동일하고 두 번째행은 마지막에서 두 번째 행과 동일함.
 * 이런 식으로 알고리즘을 짰음.
 * **/