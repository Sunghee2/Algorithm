#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

long long init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end) {
    if(start == end) return tree[node] = arr[start];
    else return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2) + init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if(index < start || index > end) return;
    
    tree[node] = tree[node] + diff;
    if(start != end) {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    
    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
    int testcase, n, m;
    scanf("%d", &testcase);

    while(testcase--) {
        scanf("%d %d", &n, &m);
        vector<long long> arr(n);

        int watch_mv, top = 0, num = 0;
        for(int i = 0; i < n; i++) {
            arr[i] = num++;
        }

        int h = (int)ceil(log2(n));
        int tree_size = (1 << (h + 1));
        vector<long long> tree(tree_size);

        init(arr, tree, 1, 0, n - 1);

        for(int i = 0; i < m; i++) {
            scanf("%lld", &watch_mv);
            update(tree, 1, 0, n - 1, top, 1);
            update(tree, 1, 0, n - 1, watch_mv - 1, -1);

            top = watch_mv - 1;
        }
    }
}


/**
 * 세그먼트 트리
 * 
 * 영화를 다 보면 맨 위에 올려 놓음 - 0이 됨
 * **/