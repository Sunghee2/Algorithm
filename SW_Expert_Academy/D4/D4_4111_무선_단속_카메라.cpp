#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, ans;
int camera[100001];

int main() {
    int testcase;
    scanf("%d", &testcase);
    for(int tc = 1; tc <= testcase; tc++) {
        scanf("%d", &n);
        scanf("%d", &k);
        memset(camera, 0, sizeof(camera));
        for(int i = 0; i < n; i++) {
            scanf(" %d", &camera[i]);
        }

        sort(camera, camera + n);
        
        vector<int> dist(n - 1);
        for(int i = 0; i < n - 1; i++) {
            dist.push_back(camera[i + 1] - camera[i]);
        }

        sort(dist.begin(), dist.end());

        ans = 0;
        for(int i = 0; i < dist.size() - (k - 1); i++) {
            ans += dist[i];
        }

        printf("#%d %d\n", tc, ans);
    }
}

/**
 * 그리디 알고리즘
 * 각 카메라의 거리를 구하고 정렬한 후
 * 수신기 개수 - 1 전까지 더해줌. 크기가 큰 것 빼버림
 * **/