#include <iostream>
#define MAX 101
using namespace std;

int q, n;
long long p_cost;
int cost[MAX];

int main() {
    cin >> q;
    for(int t = 0; t < q; t++) {
        cin >> n;
        p_cost = 0;
        for(int i = 0; i < n; i++) {
            cin >> cost[i];
            p_cost += cost[i];
        }

        for(int i = (p_cost / n) - 1; i < 2147483647; i++) {
            long long tmp_cost = i * n;
            if(tmp_cost >= p_cost) {
                cout << i << endl;
                break;
            }
        }
    }
}