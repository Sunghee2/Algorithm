#include <iostream>
#include <math.h>
using namespace std;

int wheels[4][8];
int wheel_idx[4];

void changeDirection(int wheel_num, int direction) {
    wheel_idx[wheel_num] -= direction;
    if(wheel_idx[wheel_num] == -1) wheel_idx[wheel_num] = 7;
    else if(wheel_idx[wheel_num] == 8) wheel_idx[wheel_num] = 0;    
}

int getLeftPoint(int idx) {
    return idx > 1? idx - 2 : 8 - (2 - idx);
}

int getRightPoint(int idx) {
    return idx < 6? idx + 2 : idx - 6;
}

void rotate(int wheel_num, int direction) {
    int tmp_num = wheel_num;
    int idx = wheel_idx[tmp_num];
    int left_num = wheels[tmp_num][getLeftPoint(idx)];
    int tmp_direction = -direction;
    while(0 < tmp_num) {
        if(left_num != wheels[tmp_num - 1][getRightPoint(wheel_idx[tmp_num - 1])]) {
            left_num = wheels[tmp_num - 1][getLeftPoint(wheel_idx[tmp_num - 1])];
            changeDirection(tmp_num - 1, tmp_direction);
        } else break;

        tmp_num--;
        tmp_direction = -tmp_direction;
    }

    tmp_num = wheel_num;
    int right_num = wheels[tmp_num][getRightPoint(idx)];
    tmp_direction = -direction;
    while(tmp_num < 3) {
        if(right_num != wheels[tmp_num + 1][getLeftPoint(wheel_idx[tmp_num + 1])]) {
            right_num = wheels[tmp_num + 1][getRightPoint(wheel_idx[tmp_num + 1])];
            changeDirection(tmp_num + 1, tmp_direction);
        } else break;

        tmp_num++;
        tmp_direction = -tmp_direction;
    }

    changeDirection(wheel_num, direction);
}

int sumWheels() {
    int sum = 0;
    for(int i = 0; i < 4; i++) {
        sum += wheels[i][wheel_idx[i]] * (int) pow(2, i);
    }
    return sum;
}

int main() {
    int k, wheel_num, direction;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 8; j++) {
            scanf("%1d", &wheels[i][j]);
        }
    }
    scanf("%d", &k);
    while(k--) {
        scanf("%d %d", &wheel_num, &direction);
        rotate(wheel_num - 1, direction);
    }
    printf("%d\n", sumWheels());
}

/**
 * 맨 처음에 문제가 간단한 것 같아 알고리즘 생각 정리를 안하고 풀다보니 다소 지저분하게 푼 것 같다..
 * 입력으로 톱니바퀴 상태를 입력받고 회전할 톱니바퀴 번호와 방향(시계/반시계) 입력받게 됨
 * 톱니바퀴 회전하는 것을 모든 배열을 이동시킬까 고민했는데 막상 쓰는 것은 12시 방향, 3시 방향(getLeftPoint함수), 9시방향(getRightPoint함수) 숫자뿐이라서
 * 12시 방향으로 idx번호를 넣어 바꾸는 것으로 함(wheel_idx배열) -> 변경하는 것은 changeDirection함수
 * 
 * 조건이 만약 A가 회전했을 때 양 옆에 맞닿은 다른 톱니바퀴와 극이 다르면 A 방향과 반대로 양 옆을 회전시켜야 함.
 * -> 즉 A, B, C, D가 있고 B가 시계 방향으로 회전한다면
 * -> B의 9시 방향 숫자와 A의 3시 방향 숫자가 다른지 확인 -> 다르면 A를 시계 반대 방향으로 회전
 * -> B의 3시 방향 숫자와 C의 9시 방향 숫자가 다른지 확인 -> 다르면 C를 시계 반대 방향으로 회전
 * -> 만약 여기서 C가 회전했다면, C의 3시 방향과 D의 9시 방향 숫자가 다른지 확인 -> 다르면 D를 시계 방향으로 회전 << 이 부분을 놓쳤었음. 주어진 입력의 반대 방향이 아닌 바로 옆에서 회전한 방향의 반대임!!
 * 
 * 그래서 회전 입력 받을 때마다
 * rotate에 들어가게 되는데
 * 첫 while문은 tmp_num 숫자를 줄이면서 왼쪽을 확인하는데 만약 값이 동일해서 회전하지 않으면 break로 종료
 * 두번째 while문은 tmp_num 숫자를 늘리면서 오른쪽을 확인하는데 만약 값이 동일해서 회전하지 않으면 break로 종료
 * 마지막 changeDirection은 입력받은 톱니바퀴를 가장 마지막에 회전시키게 됨.
 * (왜냐하면 회전하는 조건(값이 동일한지)이 회전한 뒤의 상태가 아닌 이전 상태를 보고 해야되기 때문)
 * **/