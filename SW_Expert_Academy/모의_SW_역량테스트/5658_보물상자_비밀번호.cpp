#include <iostream>
#include <set>
#define MAX 29
using namespace std;

int T, N, K;
char map[MAX];

int main() {
    scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++) {
        set<string> s;
        scanf("%d %d", &N, &K);
        for(int i = 0; i < N; i++) {
            scanf(" %c", &map[i]);
        }

        for(int i = 0; i < N; i++) {
            string str = "";
            int idx = 0;
            for(int j = 0; j <= 2; j++) {
                if(i + j < N) str += map[i + j];
                else str += map[idx++];
            }

            s.insert(str);
            cout << str << endl;
        }
    }
}