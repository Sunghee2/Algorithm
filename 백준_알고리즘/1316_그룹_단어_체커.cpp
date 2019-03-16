#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, num = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        bool visited[27] = { 0 }, flag = false;

        string str;
        cin >> str;

        char pre_alphabet = '.';
        for(int i = 0; i < str.length(); i++) {
            int alphabet_to_num = str.at(i) - 'a';
            if((visited[alphabet_to_num] == 1) && (pre_alphabet != str.at(i))) {
                flag = true;
                break;
            }

            pre_alphabet = str.at(i);
            visited[alphabet_to_num] = true;
        }

        if(flag == 0) num++;
    }
    printf("%d\n", num);
}