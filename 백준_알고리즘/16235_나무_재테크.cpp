#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 11
using namespace std;

typedef struct {
    int x, y, age;
} Tree;

int N, M, K, x, y, z, year = 0;
int map[MAX][MAX], nourishment[MAX][MAX];
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
vector<pair<int, int> > fall;
vector<Tree> summer;
vector<int> trees[MAX][MAX], tmp_trees[MAX][MAX];

void spendSummer() {
    for(int i = 0; i < summer.size(); i++) {
        int x = summer[i].x;
        int y = summer[i].y;
        int age = summer[i].age;

        map[x][y] += age / 2;
    }
}

void spendSpring() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(trees[i][j].size() == 0) continue;
            tmp_trees[i][j].clear();

            sort(trees[i][j].begin(), trees[i][j].end());

            int size = trees[i][j].size();
            for(int k = 0; k < size; k++) {
                int age = trees[i][j][k];

                if(age <= map[i][j]) {
                    map[i][j] -= age;
                    tmp_trees[i][j].push_back(age + 1);

                    if((age + 1) % 5 == 0) {
                        fall.push_back(make_pair(i, j));
                    }
                } else {
                    Tree nt = { i, j, age };
                    summer.push_back(nt);
                }
            }
        }
    }
}

void spendFall() {
    for(int i = 0; i < fall.size(); i++) {
        int x = fall[i].first;
        int y = fall[i].second;
        for(int k = 0; k < 8; k++) {
            int ni = x + dx[k];
            int nj = y + dy[k];

            if(0 > ni || ni >= N || 0 > nj || nj >= N) continue;

            tmp_trees[ni][nj].push_back(1);
        }
    }
}

void spendWinter() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            map[i][j] += nourishment[i][j];
        }
    }   
}

void copy() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            trees[i][j].clear();
            for(int k = 0; k < tmp_trees[i][j].size(); k++) {
                trees[i][j].push_back(tmp_trees[i][j][k]);
            }
        }        
    }
}

void invest() {
    while(year++ < K) {
        fall.clear();
        summer.clear();
        spendSpring();
        spendSummer();
        spendFall();
        spendWinter();
        copy();
    }
}

int countTree() {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cnt += trees[i][j].size();
        }        
    }
    return cnt;
}

void initMap() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            map[i][j] = 5;
        }
    }    
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf(" %d", &nourishment[i][j]);
        }
    }

    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &x, &y, &z);
        trees[x - 1][y - 1].push_back(z);
    }

    initMap();
    invest();
    printf("%d\n", countTree());
}

/**
 * 이거 시간 초과 엄청 함.. 일단 시간초과 난 알고리즘
 * 1. 우선순위 큐로 작은 것 먼저 pop하도록 하고 가을이면 5인 것을 확인하기 위해 다 팝해서 확인한 뒤 다시 집어넣음
 * 2. 위에서 가을만 vector로 따로 저장해서 넣고 빼는 것 개선...(그래도 안 되었음)
 * 3. 결국 벡터로 바꿈. 벡터도 Tree struct(x, y, age)가지고 있는 벡터로 했는데 시간초과 남..
 * 
 * 결국 벡터 2차원 배열로 해결함...(왜 3번이랑 달리 시간초과가 안나는지 모르겠음....)
 * 더 공부해야할 듯..ㅠㅠ
 * **/