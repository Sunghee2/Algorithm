#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int num = 0;
    string str, find_str;
    getline(cin, str);
    getline(cin, find_str);

    char arr_str[str.length()];
    char arr_find_str[find_str.length()];
    strcpy(arr_str, str.c_str());
    strcpy(arr_find_str, find_str.c_str());

    for(int i = 0; i < str.length(); i++) {
        if(strncmp(arr_str + i, arr_find_str, find_str.length()) == 0) {
            num++;
            i += find_str.length() - 1;
        }
    }

    cout << num << "\n";
}

/**
 * 그리디 알고리즘
 * 
 * 처음부터 있는지 확인하고 있으면 찾은 문자만큼 건너뛰어서 다시 찾음.
 * 없으면 다음 글자로 넘어가서 다시 찾음.
 * 
 * strncmp는 문자열을 비교하는데 마지막 인수에 비교할 문자의 개수를 넣을 수 있음. 
 * **/