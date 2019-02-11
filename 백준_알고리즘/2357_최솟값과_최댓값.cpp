#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

// 세그먼트 트리를 만드는 함수
// arr 입력 받은 숫자 배열, tree 세그먼트 트리 만드는 배열(max, min 넣어야 하기 때문에 이차원)
// index 0이면 min 1이면 max값 담당, node 세그먼트 트리 노드 번호, start ~ end는 node가 담당하는 범위
int init(vector<int> &arr, vector<vector<int> > &tree, int node, int index, int start, int end) {
    // start와 end가 동일 -> 리프 노드
    if(start == end) { 
        return tree[node][index] = arr[start];
    } else {
        if(index == 0) return tree[node][0] = min(init(arr, tree, node * 2, index, start, (start + end) / 2), init(arr, tree, node * 2 + 1, index, (start + end) / 2 + 1, end));
        else return tree[node][1] = max(init(arr, tree, node * 2, index, start,(start + end) / 2), init(arr, tree, node * 2 + 1, index, (start + end) / 2 + 1, end));
    }
}

// Max값을 구하는 함수
// 나머지 인자는 위 함수의 설명과 동일하고 left ~ right는 Max값을 구하고자 하는 구간
int getMax(vector<vector<int> > &tree, int node, int start, int end, int left, int right) {
    // 겹치지 않는 경우 - max값 구하는 것이므로 0 리턴
    if(left > end || right < start) return 0;
    // 구하고자 하는 구간이 [start, end]를 포함하는 경우 - node 값 리턴
    if(left <= start && end <= right) return tree[node][1];

    // [start, end]가 구하고자 하는 구간을 포함하는 경우 & [start, end]와 [left, right]가 겹쳐있는 경우 - 왼쪽 자식, 오른쪽 자식 탐색
    return max(getMax(tree, node * 2, start, (start + end) / 2, left, right), getMax(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

// Min값을 구하는 함수
int getMin(vector<vector<int> > &tree, int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 1000000000;
    if(left <= start && end <= right) return tree[node][0];

    return min(getMin(tree, node * 2, start, (start + end) / 2, left, right), getMin(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    vector<int> arr(n);

    //트리 크기 구하기
    int h = (int) ceil(log2(n));
    int tree_size = (1 << (h + 1));

    vector<vector<int> > tree(tree_size, vector<int>(2, 0));

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 세그먼트 트리 만들기
    init(arr, tree, 1, 0, 0, n - 1);
    init(arr, tree, 1, 1, 0, n - 1);


    while(m--) {
        scanf("%d %d", &a, &b);
        printf("%d %d\n", getMin(tree, 1, 0, n - 1, a - 1, b - 1), getMax(tree, 1, 0, n - 1, a - 1, b - 1));
    }
}

/**
 * 세그먼트 트리
 * 
 * 몇 개를 전역변수로 만들었으면 함수 인자가 더 줄어서 깨끗해 보일 수 있었을 듯... 
 * https://www.acmicpc.net/blog/view/9 여기 코드 보고 공부함
 * **/