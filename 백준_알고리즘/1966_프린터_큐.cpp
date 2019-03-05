#include <cstdio>
#include <queue>
using namespace std;

int main() {
    // n: 문서의 수, m: 몇 번째로 인쇄되었는지 궁금한 문서
    int testcase, n, m, v; 
    scanf("%d", &testcase);

    while(testcase--) {
        int count = 0;
        priority_queue<int> pq;
        queue<pair<int, int> > q;

        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) {
            scanf("%d", &v);
            q.push(make_pair(v, i));
            pq.push(v);
        }

        while(!q.empty()) {
            int value = q.front().first;
            int index = q.front().second;
            q.pop();

            if(pq.top() == value) {
                pq.pop();
                count++;
                if(index == m) {
                    printf("%d\n", count);
                    break;
                }
            } else {
                q.push(make_pair(value, index));
            }
        }
    }
}

/**
 * map, vector..이것저것하다가 결국 다른 사람 아이디어 이용함ㅠ
 * 큐와 우선순위큐를 같이 사용..!
 * 큐에는 value, index를 넣고 우선순위큐에는 value만 넣음
 * 그리고 큐를 pop해서 나온 value가 우선순위큐 맨 위의 value와 맞는지 확인함
 * 다르다면 pop한 value, index 를 다시 큐에 넣음(맨 뒤로 이동)
 * 하지만 같다면 같았던 우선순위큐의 맨 위 value를 pop하고 count++함
 * 이때 만약 index가 우리가 찾으려는 인쇄 문서 index와 같다면 count를 출력하고 종료함
 * **/