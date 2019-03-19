#include <iostream>
#include <string>
using namespace std;

int phone[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };

string wordToNum(string word) {
    string ret = "";
    for(int i = 0; i < word.size(); i++) {
        int num = phone[word.at(i) - 'a'];
        ret += to_string(num);
    }
    return ret;
}

int main() {
    int testcase, word_num;
    string s, word;
    scanf("%d", &testcase);

    for(int tc = 1; tc <= testcase; tc++) {
        int ans = 0;
        cin >> s >> word_num;
        for(int w = 0; w < word_num; w++) {
            cin >> word;
            if(s == wordToNum(word)) ans++;
        }
        printf("#%d %d\n", tc, ans);
    }
}

/**
 * 처음에 s를 int로 받았었는데 틀렸음.. 그 이유는 s 길이가 1000까지 갈 수 있다는 거때문이였음ㅠㅠ
 * 항상 범위 확인하자..!
 * phone이라는 배열을 미리 만들어놓았음. 각 알파벳을 int로 바꿨을 때를 인덱스로 생각해서 미리 222 넣어둠.
 * 그리고 단어를 입력받으면 wordToNum()를 통해 한 글자 씩 for문 통해 봄.
 * 알파벳을 int로 바꾼 값을 인덱스로 phone에서 숫자를 가져오고 이걸 다 합쳐서 리턴함
 * 이 값이랑 s값이랑 같다면 +1 함.
 * **/