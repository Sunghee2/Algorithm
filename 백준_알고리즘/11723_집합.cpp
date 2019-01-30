#include <iostream>
using namespace std;

int main() {
    int testcase, set = 0, x;
    char command[6];
    scanf("%d", &testcase);

    while(testcase-- > 0) {
        scanf("%s", command);
        if(command[1] == 'd') {
            scanf("%d", &x);
            set |= (1 << x);
        } else if(command[0] == 'r') {
            scanf("%d", &x);
            set &= ~(1 << x);
        } else if(command[0] == 'c') {
            scanf("%d", &x);
            if(set & (1 << x)) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if(command[0] == 't') {
            scanf("%d", &x);
            set ^= (1 << x);
        } else if(command[1] == 'l') {
            set = ((1 << 21) - 1);
        } else if(command[0] == 'e') {
            set = 0;
        }
    }
}

/**
 * 비트마스크 기본 문제
 * 
 * c++ 접한지 얼마 안되어서 문자열이 switch 안된다는 것을 처음 알았다.. 그래서 if문으로 다 바꿈.
 * **/