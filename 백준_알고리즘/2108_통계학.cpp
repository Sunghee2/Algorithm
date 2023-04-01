#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#define MAX 500001
using namespace std;

int N;
int arr[MAX];
vector<pair<int, int> > v;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}

void getAvg() {
    int sum = 0;
    for(int i = 0; i < N; i++) sum += arr[i];

    printf("%d\n", (int) round((double) sum / N));
}

void getMid() {
    if(N % 2 == 0) {
        int sum = arr[N / 2];
        sum += arr[(N / 2) - 1];
        printf("%d\n", sum / 2);
    }
    else printf("%d\n", arr[N / 2]);
}

void getMode() {
    for(int i = 0; i < N; i++) {
        if(i != 0 && arr[i] == arr[i - 1]) {
            int idx = v.size() - 1;
            v[idx].second++;
        } else {
            v.push_back(make_pair(arr[i], 1));
        }
    }

    sort(v.begin(), v.end(), cmp);

    if(v[0].second == v[1].second) printf("%d\n", v[1].first);
    else printf("%d\n", v[0].first);
}

void getDiff() {
    printf("%d\n", arr[N - 1] - arr[0]);
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    getAvg();
    getMid();
    getMode();
    getDiff();
}

/**
 * 최빈값은 vector<pair<int, int> > 해서 정렬하면 됨.
 * 그리고 이미 arr가 정렬되어있어서 넣을 때 O(n^2) 안해도됨.
 * **/