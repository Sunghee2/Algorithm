#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int l, c;
vector<int> arr;
int visited[27];

void dfs(int index, int num, int vowel, int consonant) {
    if(num == l + 1) {
        if(vowel > 0 && consonant >= 2) {
            for(int i = 0; i < 27; i++) {
                if(visited[i] == 1) {
                    printf("%c", i + 'a');
                }
            }
            printf("\n");
        }
    }

    for(int i = index; i < arr.size(); i++) {
        if(visited[arr[i]] == 0) {
            visited[arr[i]] = 1;
            if(arr[i] == 0 || arr[i] == 4 || arr[i] == 8 || arr[i] == 14 || arr[i] == 20) {
                dfs(i, num + 1, vowel + 1, consonant);
            } else {
                dfs(i, num + 1, vowel, consonant + 1);
            }
            visited[arr[i]] = 0;
        }
    }
}

int main() {
    char a;

    scanf("%d %d", &l, &c);
    for(int i = 0; i < c; i++) {
        scanf(" %c", &a);
        arr.push_back(a - 'a');
    }

    sort(arr.begin(), arr.end());
    dfs(0, 1, 0, 0);
}

/**
 * 백트래킹 문제
 * 문자를 받은 후 숫자로 바꿔 벡터에 넣은 후 정렬함
 * index(지금 자리부터) ~ 끝까지 다음에 갈 곳이 모음인지 자음인지 구분하여 재귀
 * 
 * https://www.acmicpc.net/problem/2661  이 문제도 풀어볼 것!
 *  **/