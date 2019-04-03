#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int ans;
string str;

void isPalindrome(string s) {
    int t = 0, d = s.length() - 1;
    while(t < d) {
        if(s.at(t++) != s.at(d--)) return;
    }
    ans++;
}

void dfs(string s, int index) {
    if(s.length() > 1) {
        isPalindrome(s);
    }
    if(index == str.length() - 1)   return;
    
    s += str.at(index + 1);
    dfs(s, index + 1);
}

void callDFS() {
    for(int i = 0; i < str.length() - 1; i++) {
        string s(1, str.at(i));
        dfs(s, i);
    }
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    for(int tc = 1; tc <= testcase; tc++) {
        cin >> str;
        ans = str.length();
        sort(str.begin(), str.end());
        callDFS();
        printf("#%d %d\n", tc, ans);
    }
}


/**
 * 여전히 문제를 잘못읽음.. 최대가 나오도록 문자열을 재구성해야됨. -> 정렬함..
 * 끝에 다가 하나씩 두는 것과 옆에 하나씩 묶이는 개수가 어차피 똑같기 때문.
 * 시간은 별로 신경안쓰는 듯.. dp가 아닌데 통과됨..
 * **/