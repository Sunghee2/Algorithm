#include <iostream>
#define MAX 12
using namespace std;

int n, max_num = -100000000, min_num = 1000000000;
int num[MAX], num_operator[4];

void dfs(int index, int plus, int minus, int multiply, int division, int result) {
    if(index == n) {
        max_num = max_num < result? result : max_num;
        min_num = min_num > result? result : min_num;
        return;
    }

    if(num_operator[0] > plus)
        dfs(index + 1, plus + 1, minus, multiply, division, result + num[index]);
    if(num_operator[1] > minus)
        dfs(index + 1, plus, minus + 1, multiply, division, result - num[index]);
    if(num_operator[2] > multiply)
        dfs(index + 1, plus, minus, multiply + 1, division, result * num[index]);
    if(num_operator[3] > division)
        dfs(index + 1, plus, minus, multiply, division + 1, result / num[index]);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for(int i = 0; i < 4; i++) {
        cin >> num_operator[i];
    }

    dfs(1, 0, 0, 0, 0, num[0]);
    cout << max_num << endl << min_num << endl;
}