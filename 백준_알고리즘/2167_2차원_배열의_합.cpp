#include <iostream>

int main() {
    int row, col, testcase, i, j, x, y, sum;
    scanf("%d %d", &row, &col);

    int arr[row + 1][col + 1];
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d %d %d", &i, &j, &x, &y);

        sum = 0;
        for(int k = i; k <= x; k++) {
            for(int l = j; l <= y; l++) {
                sum += arr[k][l];
            }
        }

        printf("%d\n", sum);
    }
}


/**
 * dp문제인데 그냥 for문으로 sum했더니 해결된 문제..
 * 
 * dp로는 그냥 (1, 1)부터 (i, j)까지의 합으로 배열에 저장함.
 * 거기서 i-1까지부분 빼주고 j-1부분까지 빼주면 이 두개에 겹치는 부분이 2번 빼지므로 이 부분을 한 번 더해주면 될 것 같음. 
 * 그림 그리면 쉬움.
 * **/