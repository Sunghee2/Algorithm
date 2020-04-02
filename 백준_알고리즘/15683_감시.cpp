#include <iostream>
#include <vector>
#include <cstring>
#define MAX 9
#define INF 987654321
using namespace std;

typedef struct {
    int x, y, type;
} CCTV;

int n, m, min_bline_spot = INF;
int office[MAX][MAX];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<CCTV> cctv;

void getMinBlindSpot() {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!office[i][j]) cnt++;
        }
    }
    
    if(cnt < min_bline_spot) min_bline_spot = cnt;
}

void watchOffice(int x, int y, int d) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    while(office[nx][ny] != 6 && 0 <= nx && nx < n && 0 <= ny && ny < m) {
        office[nx][ny] = -1;
        nx += dx[d];
        ny += dy[d];
    }
}

void runCCTV(int idx) {
    if(idx == cctv.size()) {
        getMinBlindSpot();
        return;
    }
    
    int tmp_office[MAX][MAX];
    memcpy(tmp_office, office, sizeof(office));
    CCTV cur_cctv = cctv[idx];
    switch(cur_cctv.type) {
        case 1:
            for(int i = 0; i < 4; i++) {
                watchOffice(cur_cctv.x, cur_cctv.y, i);
                runCCTV(idx + 1);
                memcpy(office, tmp_office, sizeof(office));
            }
            break;
        case 2:
            for(int i = 0; i < 2; i++) {
                watchOffice(cur_cctv.x, cur_cctv.y, i);
                watchOffice(cur_cctv.x, cur_cctv.y, i + 2);
                runCCTV(idx + 1);
                memcpy(office, tmp_office, sizeof(office));                
            }
            break;
        case 3:
            for(int i = 0; i < 4; i++) {
                watchOffice(cur_cctv.x, cur_cctv.y, i);
                watchOffice(cur_cctv.x, cur_cctv.y, (i + 1) % 4);
                runCCTV(idx + 1);
                memcpy(office, tmp_office, sizeof(office)); 
            }
            break;
        case 4:
            for(int i = 0; i < 4; i++) {
                watchOffice(cur_cctv.x, cur_cctv.y, i);
                watchOffice(cur_cctv.x, cur_cctv.y, (i + 1) % 4);
                watchOffice(cur_cctv.x, cur_cctv.y, (i + 2) % 4);
                runCCTV(idx + 1);
                memcpy(office, tmp_office, sizeof(office));                   
            }
            break;
        case 5:
            for(int i = 0; i < 4; i++) {
                watchOffice(cur_cctv.x, cur_cctv.y, i);
            }
            runCCTV(idx + 1);
            memcpy(office, tmp_office, sizeof(office));
            break;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %d", &office[i][j]);
            if(office[i][j] && office[i][j] != 6) {
                CCTV new_cctv = { i, j, office[i][j] };
                cctv.push_back(new_cctv);
            }
        }
    }

    runCCTV(0);

    printf("%d\n", min_bline_spot);    
}


/**
 * 2048 풀고 풀어서 그런지 생각보다 쉽게 풀림.. 한동안 시뮬만 풀어야 될 듯 함..
 * 그래도 맨처음에 CCTV 종류(1, 2, 3, 4, 5)의 모양에 맞춰서 어떻게 할 지 힘들었음.ㅠ
 * 처음에 dx, dy 배열을 상 하 우 좌 이런 순서로 했는데 3번째 직각 부분에서 어떻게 호출할 지 한참 고민하다
 * 그냥 배열을 바꿔버림(진작 이렇게 했으면 될 걸....ㅠ 괜한 오기로 붙잡고 있었음)
 * 
 * 1. 입력받을 때 CCTV가 나오면 위치와 타입을 벡터(cctv)에 저장함
 * 2. runCCTV에서 벡터 순서대로 CCTV 감시를 시작하게 됨. 
 * 3. 벡터 사이즈만큼 dfs 돌았으면 모든 CCTV가 켜진 것 이기 때문에 0(사각지대)를 세고 종료
 * 4. switch 문 들어가기 전에 이전 상태를 기억해줘야하기 때문에 office 배열을 tmp_office에 복사해줌.
 * 5. cctv 종류대로 watchOffice의 while 루프를 통해 감시함. (감시할 수 있는 곳은 -1로 변경해줌)
 * **/