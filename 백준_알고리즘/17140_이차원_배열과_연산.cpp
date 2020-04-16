#include <iostream>
#include <cstring>
#include <queue>
#define MAX 201
using namespace std;

int r, c, k, row = 3, col = 3, min_time = 987654321;
int arr[MAX][MAX], num[101];

void solve(int time) {
    if(arr[r - 1][c - 1] == k) {
        min_time = time < min_time ? time : min_time;
        return;
    }

    if(time > 100) {
        min_time = -1;
        return;
    }

    if(row >= col) {
        for(int i = 0; i < row; i++) {
            memset(num, 0, sizeof(num));
            priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
            for(int j = 0; j < col; j++) {
                if(arr[i][j]) {
                    num[arr[i][j]] += 1;
                    arr[i][j] = 0;
                }
            }

            for(int j = 0; j < 101; j++) if(num[j]) pq.push(make_pair(num[j], j));
            int length = pq.size() * 2;
            for(int j = 0; j < length; j += 2) {
                arr[i][j] = pq.top().second;
                arr[i][j + 1] = pq.top().first;
                pq.pop();
            }
            col = col < length? length : col;
        }
    } else {
        for(int i = 0; i < col; i++) {
            memset(num, 0, sizeof(num));
            priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
            for(int j = 0; j < row; j++) {
                if(arr[j][i]) {
                    num[arr[j][i]] += 1;
                    arr[j][i] = 0;
                }
            }
            for(int j = 0; j < 101; j++) if(num[j]) pq.push(make_pair(num[j], j));
            int length = pq.size() * 2;
            for(int j = 0; j < length; j += 2) {
                arr[j][i] = pq.top().second;
                arr[j + 1][i] = pq.top().first;
                pq.pop();
            }
            row = row < length? length : row;
        }
    }

    solve(time + 1);
}

int main() {
    scanf("%d %d %d", &r, &c, &k);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf(" %d", &arr[i][j]);
        }
    }

    solve(0);

    printf("%d\n", min_time);
}

/**
 * 시뮬레이션.
 * map으로 풀려다가 key, value 모두 정렬해야 되어서ㅠ
 * 우선순위 큐로 풀었음.
 * 
 * 입력 받고 solve 재귀함수로 1초 지날때마다 R 또는 C 연산함.
 * R 연산은 첫 번째 for문에서 개수를 세서 배열에 넣어주고
 * 두 번째 for 문에서 개수 센 것을 우선순위 큐에 넣음
 * 세 번째 for 문에서 큐에 있는 것을 배열에 넣는 것.
 * 
 * 우선순위 큐가 first -> second 순으로 비교하기 때문에
 * 등장 횟수, 수 순으로 넣음.
 * **/