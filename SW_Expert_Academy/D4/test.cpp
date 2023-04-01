#include <stdio.h>
 
char map[51][51];
int color[51][3];//color[i][j] i번째 줄을 j번째 색으로 바꾸는데 드는 비용 0=W 1=B 2=R
int n, m;
int min = 2e9;
 
void dfs(int ptr, int col, int sum, int flag[])
{
    if (ptr == n - 1)
    {
        for (int i = 0; i < 3; i++)
        {
            if (flag[i] == 0)
                return;
        }
        if (sum < min)
            min = sum;
        return;
    }
    for (int j = col; j <= col+1 && j<3; j++)
    {
        int check = 0;
        if (flag[j] == 0)
        {
            check = 1;
            flag[j] = 1;
        }
        dfs(ptr+1, j, sum + color[ptr+1][j], flag);
        if (check == 1)
        {
            flag[j] = 0;
            check = 0;
        }
    }
}
 
int main(void)
{
    int T;
    setbuf(stdout, NULL);
    scanf("%d\n", &T);
 
    for (int test_cast = 1; test_cast <= T; test_cast++)
    {
        for (int i = 0; i < 51; i++)//초기화
        {
            for (int j = 0; j < 51; j++)
                map[i][j] = 0;
            for (int j = 0; j < 3; j++)
                color[i][j] = 0;
        }
        min = 2e9;
        
        scanf("%d %d\n", &n,&m);
        for (int i = 0; i < n; i++)
            scanf("%s", map[i]);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)//모두 W로 바꿔야함
            {
                for (int j = 0; j < m; j++)
                {
                    if (map[i][j] != 'W')
                    {
                        color[i][0]++;
                    }
                }
            }
            else if (i == 1)//W or B
            {
                for (int j = 0; j < m; j++)
                {
                    if (map[i][j] != 'W')
                    {
                        color[i][0]++;
                    }
                    if (map[i][j] != 'B')
                    {
                        color[i][1]++;
                    }
                }
            }
            else if (i == n - 2)//B or R
            {
                for (int j = 0; j < m; j++)
                {
                    if (map[i][j] != 'R')
                    {
                        color[i][2]++;
                    }
                    if (map[i][j] != 'B')
                    {
                        color[i][1]++;
                    }
                }
            }
            else if (i == n - 1)//R
            {
                for (int j = 0; j < m; j++)
                {
                    if (map[i][j] != 'R')
                    {
                        color[i][2]++;
                    }
                }
            }
            else// W or B or R
            {
                for (int j = 0; j < m; j++)
                {
                    if (map[i][j] != 'W')
                    {
                        color[i][0]++;
                    }
                    if (map[i][j] != 'B')
                    {
                        color[i][1]++;
                    }
                    if (map[i][j] != 'R')
                    {
                        color[i][2]++;
                    }
                }
            }            
        }
        int flag[3] = { 1, 0, 0 };
        dfs(0, 0, color[0][0], flag);
        printf("#%d %d\n", test_cast, min);
    }
}
