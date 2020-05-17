#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int N, M, num, diff = 0;
bool failure[10];

bool checkNum(string s) {
    for(int i = 0; i < s.length(); i++) {
        if(failure[s[i] - '0']) return true;
    }
    return false;
}

int main() {
    scanf("%d", &N);
    scanf("%d", &M);
    while(M--) {
        scanf("%d", &num);
        failure[num] = true;
    }

    int d = abs(N - 100);
    while(1) {
        int num1 = N - diff, num2 = N + diff;
        if(num1 == 100 || num2 == 100) break;
        bool res_num1 = checkNum(to_string(num1)), res_num2 = checkNum(to_string(num2));
        if((num1 >= 0 && !res_num1) || !res_num2) {
            int len_num1 = to_string(num1).length(), len_num2 = to_string(num2).length();
            if(!res_num1 && !res_num2) diff += len_num1 > len_num2? len_num2 : len_num1;
            else if(!res_num2) diff += len_num2;
            else diff += len_num1;

            diff = diff < d ? diff : d;
            break;
        }

        diff++;
    }

    printf("%d\n", diff);
}

/**
 * 문제 알고리즘 생각하는 건 쉬웠지만
 * 조건 처리가 생각보다 많아서 정답률이 낮은 듯ㅠㅠ
 * **/