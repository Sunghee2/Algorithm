#include <iostream>
using namespace std;

int testcase, num = 0;
int word[26];

void dfs(int index, int sentence) {
    if(index == testcase) {
        if(sentence == (1 << 26) - 1) num++;
        return;
    }

    dfs(index + 1, sentence);
    dfs(index + 1, sentence | word[index]);
}

int main() {
    cin >> testcase;

    string input_str;
    for(int i = 0; i < testcase; i++) {
        cin >> input_str;
        for(int j = 0; j < input_str.length(); j++) {
            word[i] |= (1 << (input_str[j] - 'a'));
        }
    }

    dfs(0, 0);
    cout << num << "\n";
}

/**
 * 비트마스크 & dfs
 * 
 * 먼저 단어를 입력받아서 한글자씩 잘라서 순서를 구함(a=0, b=1...)
 * 해당 순서에 1을 추가함(|)
 * 그리고 dfs를 해당 단어를 추가할 경우, 추가하지 않는 경우 두 가지로 나눠서 돌림.
 * 끝까지 가고 알파벳이 다 있으면((1 << 26) - 1) num을 추가함. 하나라도 없으면 그냥 리턴.
 * 
 * **/