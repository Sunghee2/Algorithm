#include <iostream>
#define MAX 2001
using namespace std;

int n, num;
bool arr[MAX];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        arr[1000 + num] = true;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (arr[i])
        {
            printf("%d ", i - 1000);
        }
    }
}