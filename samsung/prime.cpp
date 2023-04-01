/**
 * 정점 선택을 중심으로
 * 
 * 시작정점 선택
 * MST 집합에 인접한 노드들 중 최소 가중치로 연결한 정점 선택
 * 해당 정점을 MST 집합에 포함
 * 
 * 
 * **/

#include <iostream>
#define MAX 1000
#define INF 987654321
using namespace std;

// 그래프의 인접행렬
int w[MAX][MAX];
// 인접 정점을 연결하는데 필요한 간선의 최소 가중치
int d[MAX][MAX];
// 해당 정점이 MST에 포함되어있는지
bool check[MAX];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> w[i][j];
        }
    }

    int s;
    cin >> s;
    check[s] = true;

    for (int i = 0; i < n; i++)
    {
        d[i] = w[s][i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int v; // MST 집합에 포함될 다음 번호
        // 사용하지 않은 가장 처음 것 가져옴
        for (int i = 0; i < n; i++)
        {
            if (check[i] == false)
            {
                v = i;
                break;
            }
        }

        // 가장 비용 적은지 확인
        for (int i = v + 1; i < n; i++)
        {
            if (check[i] == false && d[v] > d[i])
            {
                v = i;
            }
        }

        // MST 추가
        check[v] = true;
        // 추가한 애에 대해서 최소 가중치 갱신
        for (int i = 0; i < n; i++)
        {
            if (d[i] > w[v][i])
                d[i] = w[v][i];
        }
    }
}