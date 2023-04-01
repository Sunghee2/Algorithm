#include <stdio.h>
 
int main(void)
{
    int T;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++)
    {
        unsigned long long n;
        scanf("%llu", &n);
        int check = 0;
        unsigned long long turn = 1;
        unsigned long long mul = 1;
        while (turn < n)
        {
            if (!check)
                mul *= 4;
            turn += mul;
            check = !check;
        }
        printf("#%d %s\n", test_case,check?"Alice":"Bob");
            
 
    }
    return 0;
}
