#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int n, l, start, end, board_num = 0;
    scanf("%d %d", &n, &l);  
    
    pair<int, int> pool[n];

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &pool[i].first, &pool[i].second);
    }

    sort(pool, pool + n);

    int board = pool[0].first;
    for(int i = 0; i < n; i++) {
        // 울덩이 시작 위치에서 시작해서 board가 물웅덩이 끝 위치보다 커지면 아래 for문 종료
        // 다른 사람들 보니 이 for문 안쓰고 그냥 나눠서 생각했으면 더 빠른 시간으로 할 수 있었을 듯..
        for(int j = pool[i].first; board < pool[i].second; j++) {
            if(board < j) board = j; // 현재 널빤지 위치가 물웅덩이 시작위치보다 작은 경우 시작위치를 널빤지 위치로 맞춰줌.
            board += l; // 널빤지 크기 만큼 더해줌.
            board_num++; // 널빤지 개수 1 더해줌.
        }
    }

    printf("%d", board_num);
}

/**
 * 그리디 알고리즘
 * 
 * 물웅덩이 시작지점을 기준으로 오름차순으로 정렬하기 위해서 위와 같은 자료구조 사용했음(pool)
 * 처음에는 물웅덩이 위치의 1,000,000,001 크기의 배열로 만들었었는데 c++이 처음이다 보니.. 배열 크기 제한이 있었음..
 * 그래서 다른 자료구조를 사용해서 생각하기가 너무 힘들었음..
 * 
 * 현재는 저기에 시작 위치와 끝 위치를 저장하고
 * 시작 위치를 기준으로 오름차순으로 정렬함.
 * 
 * 널빤지는 그냥 물웅덩이 시작지점에서 계속 놓음. 물웅덩이가 끝날 때까지.
 * 다음 물웅덩이에서도 현재 널빤지 위치를 확인한 뒤
 * 널빤지가 물웅덩이 전에 끝나있으면 현재 물웅덩이 시작지점으로 널빤지 위치 조정하고 아니라면 그대로 웅덩이 덮을 때까지 널빤지 크기만큼 계속 더해줌
 * **/