#include <iostream>
#include <map>
using namespace std;

int main() {
    int testcase, num;
    scanf("%d", &testcase);

    for(int i = 1; i <= testcase; i++) {
        map<int, int> m;
        for(int j = 0; j < 3; j++) {
            scanf("%d", &num);
            map<int, int>::iterator it = m.find(num);
            if(it == m.end()) {
                m.insert(make_pair(num, 1));
            } else {
                m.erase(num);
            }
        }
        map<int, int>::iterator it = m.begin();
        printf("#%d %d\n", i, it->first);
    }
}

/**
 * map으로 써서 중복 확인.
 * 만약 map에서 입력받은 길이 값의 키가 존재하면 삭제하고
 * 없으면 넣음.
 * 그래서 마지막에는 map에 하나 밖에 남지 않게 되는데
 * 그것의 키를 출력함.
 * **/