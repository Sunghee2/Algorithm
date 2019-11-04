#include <iostream>
#include <cstring>
#define MAX 11
using namespace std;

int t, m, n, num1, num2;
// taken : 해당 idx 학생이 짝이 있는지 없는지 확인
// are_friends : 친구 짝을 나타낸 배열
bool taken[MAX], are_friends[MAX][MAX];

int countPairings() {
    int first_free = -1; 
    // 짝이 없는 학생 중 가장 idx가 빠른 것을 찾음
    for(int i = 0; i < n; i++) {
        if(!taken[i]) {
            first_free = i;
            break;
        }
    }

    int ret = 0;
    if(first_free == -1) return 1; // 짝이 모두 있는 경우 1 리턴
    for(int i = first_free + 1; i < n; i++) {
        if(!taken[i] && are_friends[i][first_free]) {
            taken[first_free] = taken[i] = true;
            ret += countPairings(); // return 1(21번째줄)을 계속 더하면서 경우의 수를 구함
            taken[first_free] = taken[i] = false; // 바로 위에서 두 개가 true인 경우를 다 찾았기 때문에 다른 경우의 수를 찾기 위해 false
        }
    }

    return ret;
}

int main() {
    cin >> t;
    for(int tc = 0; tc < t; tc++) {
        memset(taken, 0, sizeof(taken));
        memset(are_friends, 0, sizeof(are_friends));
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            cin >> num1 >> num2;
            are_friends[num1][num2] = true;
            are_friends[num2][num1] = true;
        }

        cout << countPairings() << endl;
    }

}

/**
 * 원래는 진짜 vector 그래프 처럼 만들어서 완탐을 하려했었음..
 * 완탐에도 최적화 방법이 있음..
 * 물론 문제보자마자 대충 어떻게 할 지는 떠오르지만 일단 이 문제가 난이도 '하'라는 것에 놀랐다ㅠ 
 * 아직 많이 부족함을 느꼈음..
 * 
 * 완탐에서 중복이 되지 않도록 오름차순 형식의 답만 구하는 것!
 * 그래서 가장 번호가 빠른 학생을 찾아 그 학생의 짝을 찾음.
 * 
 * 
 * 문제.
 * 항상 서로 친구인 학생들끼리만 짝을 지어 줘야 합니다.
 * 각 학생들의 쌍에 대해 이들이 서로 친구인지 여부가 주어질 때, 
 * 학생들을 짝지어줄 수 있는 방법의 수를 계산하는 프로그램을 작성하세요. 
 * 짝이 되는 학생들이 일부만 다르더라도 다른 방법이라고 봅니다. 
 * 예를 들어 다음 두 가지 방법은 서로 다른 방법입니다.
(태연,제시카) (써니,티파니) (효연,유리)
(태연,제시카) (써니,유리) (효연,티파니)
 * **/