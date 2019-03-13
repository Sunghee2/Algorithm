#include <iostream>
using namespace std;

int main() {
    int testcase, n, ans, max, input;
    bool score[10001];
    cin >> testcase;

    for(int i = 1; i <= testcase; i++) {
        cin >> n;
        ans = 1, max = 0;
        memset(score, 0, sizeof(score));
        score[0] = true;
        for(int i = 0; i < n; i++) {
            cin >> input;
            for(int j = max; j >= 0; j--) {
                if(score[j] == true) {
                    if(score[j + input] == false) {
                        max = max < j + input? j + input : max;
                        score[j + input] = true;
                        ans++;
                    }
                }
            }
        }
        
        printf("#%d %d\n", i, ans);
    }
}

/**
 * 그냥 재귀함수로 풀었더니 시간초과..
 * 그래서 dp문제로 생각함.
 * 
 * ex) 2 3 5
 * score = 0
 * (input 2) score = 0 2
 * (input 3) score = 0 2 3 5
 * (input 5) score = 0 2 3 5 7 8 10
 * 
 * score 배열을 만들어서 0을 true라고 바꿈(다 틀리면 0임)
 * 그래서 입력받을 때마다 score에서 true인 것의 인덱스와 입력받은 숫자를 더해서 나온 값을 score에 true로 바꿈
 * 근데 더할 때 앞에서부터 더하게 되면 무한정으로 계속 더해지게 됨
 * 그래서 뒤에서부터 더해야함
 * **/