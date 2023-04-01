#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#define MAX 10
using namespace std;

typedef struct {
    int x, y;
} Point;

typedef struct {
    int s, e, len;
} Dist;

int N, M, cnt, ans = 987654321;
int map[MAX][MAX];
int visited[MAX][MAX];
bool check[111];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<Dist> v;

void get_num() {
    queue<Point> q;
    int num = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(map[i][j] && !visited[i][j]) {
                Point p = { i, j };
                q.push(p);
                visited[i][j] = ++num;
                while(!q.empty()) {
                    int x = q.front().x;
                    int y = q.front().y;
                    q.pop();

                    for(int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx < 0 || nx >= N || 0 < ny || ny >= M) continue;
						if (map[nx][ny] && !visited[nx][ny]){
							visited[nx][ny] = num;
                            Point np = { nx, ny };
							q.push(np);
						}
                    }
                }
            }
        }
    }

    cnt = num;
}

void get_dist(int num) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(visited[i][j] == num) {
                for(int k = 0; k < 4; k++) {
                    for(int len = 1; len < 10; len++) {
                        int nx = i + len * dx[k];
                        int ny = j + len * dy[k];

                        if(0 > nx || nx >= N || 0 > ny || ny >= M) break;
                        if(visited[nx][ny] == num) break;
                        if(visited[nx][ny]) {
                            if(len - 1 < 2) break;
                            bool flag = false;

                            for(int a = 0; a < v.size(); a++) {
                                if(v[a].s == num && v[a].e == visited[nx][ny]) {
                                    v[a].len = min(v[a].len, len - 1);
                                    flag = true;
                                }

                                if(v[a].s == visited[nx][ny] && v[a].e == num) {
                                    v[a].len = min(v[a].len, len - 1);
                                    flag = true;
                                }
                            }

                            if(flag) break;
                            Dist d = { num, visited[nx][ny], len - 1 };
                            v.push_back(d);
                            break;
                        }
                    }
                }
            }
        }
    }    
}

bool is_connect() {
    queue<int> q;
    bool tmp[11], chk[11][11];
    memset(tmp, false, sizeof(tmp));
    memset(chk, false, sizeof(chk));
    for(int i = 0; i < v.size(); i++) {
        if(check[i]) {
            chk[v[i].s][v[i].e] = true;
            chk[v[i].e][v[i].s] = true;
        }
    }
    q.push(1);
    tmp[1] = true;
    
    int num = 1;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i = 1; i <= cnt; i++) {
            if(!tmp[i] && chk[now][i]) {
                tmp[i] = true;
                q.push(i);
                num++;
            }
        }
    }
    if(cnt == num) return true;
    return false;
}

void dfs(int cnt, int val, int now) {
    if(cnt == val) {
        if(is_connect()) {
            int sum = 0;
            for(int i = 0; i < v.size(); i++) {
                if(check[i]) sum += v[i].len;
            }
            ans = min(ans, sum);
        }
        return;
    }

    for(int i = now; i < v.size(); i++) {
        if(!check[i]) {
            check[i] = true;
            dfs(cnt + 1, val, i + 1);
            check[i] = false;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    get_num();
    for(int i = 1; i <= cnt; i++) get_dist(i);
    dfs(0, cnt - 1, 0);

    if(ans == 987654321) printf("-1\n");
    else printf("%d\n", ans);
}
