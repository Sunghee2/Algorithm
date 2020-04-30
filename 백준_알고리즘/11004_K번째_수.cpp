#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> v(n);
    for(int i = 0; i < n; i++) scanf(" %d", &v[i]);

    nth_element(v.begin(), v.begin() + (k - 1), v.end());
    printf("%d\n", v[k - 1]);
}