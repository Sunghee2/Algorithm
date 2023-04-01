#include <iostream>
#include <queue>
using namespace std;

int K, N;
int arr[101];
priority_queue<long long, vector<long long>, greater<long long> > pq;

int main() {
    scanf("%d %d", &K, &N);
    for(int i = 0; i < K; i++) {
        scanf(" %d", &arr[i]);
        pq.push(arr[i]);
    }

    int cnt = 1;
    while(cnt++ < N) {
        long long num = pq.top();
        pq.pop();

        for(int i = 0; i < K; i++) {
            long long tmp = num * arr[i];
            pq.push(tmp);

            if(num % arr[i] == 0) break;
        }
    }

    cout << pq.top() << endl;
}