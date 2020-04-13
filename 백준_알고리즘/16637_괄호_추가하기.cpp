#include <iostream>
#include <vector>
using namespace std;

int n, max_num = -987654321;
vector<int> num;
vector<char> operators;

int calculate(int num1, int num2, char op) {
    if(op == '+') return num1 + num2;
    else if(op == '-') return num1 - num2;
    else return num1 * num2;
}

void dfs(int idx, int cal_num) {
    if(idx >= n / 2) {
        if(max_num < cal_num) max_num = cal_num;
        return;
    }

    if(idx + 1 < operators.size()) {
        dfs(idx + 2, calculate(cal_num, calculate(num[idx + 1], num[idx + 2], operators[idx + 1]), operators[idx]));
    } 
    dfs(idx + 1, calculate(cal_num, num[idx + 1], operators[idx]));
}

int main() {
    scanf("%d", &n);

    char c;
    for(int i = 0; i < n; i++) {
        scanf(" %c", &c);
        if(i % 2) operators.push_back(c);
        else num.push_back(c - '0');
    }

    dfs(0, num[0]);

    printf("%d\n", max_num);
}

/**
 * 완전탐색 문제
 * 0.5초 제한이지만 n이 작아서 괜찮은 듯.
 * 
 * 식이 주어지면 괄호를 추가해서 나오는 최댓값 출력하는 것
 * 조건
 * 1. 중첩 괄호 안 됨
 * 2. 괄호 안에는 연산자 1개만 (num1 연산자 num2 형식)
 * 3. 괄호 개수 제한 없음
 * 
 * dfs로 완탐해서 풀었음
 * 입력받을 때 숫자와 연산자 나눠서 받음
 * dfs함수에서 만약 idx가 0이라면
 *  3+8*7-9*2 에서
 * 3+8만 계산하고 넘어가거나 3+(8*7)을 계산하고 넘어감
 * 전자는 괄호가 없어서 순차적으로 계산하는 것이고
 * 후자는 뒤에 괄호가 있어 괄호 먼저 계산하고 넘어가게 됨.
 * **/