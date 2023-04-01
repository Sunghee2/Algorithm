#include <iostream>
#include <map>
#define MAX 1001
using namespace std;

int T, N, M, n, m;
long long ans = 0;
int nmap[MAX], mmap[MAX];
map<int, int> m_sum;

int main() {
    scanf("%d", &T);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf(" %d", &n);
        nmap[i] = nmap[i - 1] + n;
    }
    scanf("%d", &M);
    for(int i = 1; i <= M; i++) {
        scanf(" %d", &m);
        mmap[i] = mmap[i - 1] + m;
    }

    for(int i = 1; i <= M; i++) {
        for(int j = 0; j < i; j++)  {
            m_sum[mmap[i] - mmap[j]]++;
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            ans += m_sum[T - (nmap[i] - nmap[j])];
        }
    }


    printf("%lld\n", ans);
}