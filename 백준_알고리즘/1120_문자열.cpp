#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int min_diff = b.length();
    int len_diff = b.length() - a.length();
    for(int i = len_diff; i >= 0; i--) {
        int tmp_diff = 0;
        for(int j = 0; j < a.length(); j++) {
            if(a[j] != b[i + j]) {
                tmp_diff++;
            }
        }
        
        if(min_diff > tmp_diff) min_diff = tmp_diff;
    }

    printf("%d\n", min_diff);
}


/**
 * 그리디 알고리즘 & 브루트 포스
 * 
 * a가 3글자이고 b가 6글자인 경우
 * 123___
 * 12___3
 * 1___23
 * ___123 (총 4가지)
 * 과 같은 형태로 알파벳을 넣는다. 여기서 a와 b의 차이를 최소화하기 위해서
 * 넣는 알파벳은 각 자리의 b의 알파벳을 넣는다고 가정하고(똑같은 알파벳) a와 b의 차이를 생각할 때 고려하지 않는다.
 * 그래서 결국 a와 저 b의 ___자리의 알파벳을 비교해서 차이를 세어서 최소를 구하면 된다.
 * 
 * 위의 경우는 a와 b의 글자수 차이 + 1 만큼의 경우의 수가 생긴다. 이것은 첫번째 for문(10번째줄)에 나와있다.
 * 두 번재 for문(12번째줄)에서는 a와 b의 알파벳을 비교하기 위한 for문이다. 
 * b의 ___자리는 처음에 a와 b의 차이(i)만큼 밀려나있게 된다. 그리고 하나씩 줄어듦. (ex. 차이가 4일 경우는 1234___ 같이 글자수가 4개 밀림. 123___4 그 다음은 3개로 밀려남)
 * 그리고 a와 계속 비교하기 위해서 다음자리 알파벳을 보기 위해 b[i + j] j를 더해준다. 
 * 그렇게 두 알파벳이 다르면 tmp_diff를 하나씩 더해주고 마지막에는 min과 비교한다.
 * **/