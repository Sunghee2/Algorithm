#include <iostream>
#include <cstring>
#include <queue>
#define MAX 201
using namespace std;

int A, B, C;
int water[MAX];
bool visited[MAX][MAX][MAX];

typedef struct {
    int a, b, c;
} Bucket; 

void printWater() {
    for(int i = 0; i <= 200; i++) {
        if(water[i]) printf("%d ", i);
    }
}

void bfs() {
    queue<Bucket> q;
    Bucket b = { 0, 0, C };
    q.push(b);

    while(!q.empty()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();

        if(visited[a][b][c]) continue;
        visited[a][b][c] = true;

        if(a == 0) {
            water[c] = 1;
        }

        if(a + b > B) {
            Bucket bucket = { a - (B - b), B, c};
            q.push(bucket);
        } else {
            Bucket bucket = { 0, a + b, c};
            q.push(bucket);
        }

        if(a + c > C) {
            Bucket bucket = { a - (C - c), b, C};
            q.push(bucket);
        } else {
            Bucket bucket = { 0, b, a + c};
            q.push(bucket);
        }

        if(b + a > A) {
            Bucket bucket = { A, b - (A - a), c};
            q.push(bucket);
        } else {
            Bucket bucket = { a + b, 0, c};
            q.push(bucket);
        }

        if(b + c > C) {
            Bucket bucket = { a, b - (C - c), C};
            q.push(bucket);
        } else {
            Bucket bucket = { a, 0, b + c};
            q.push(bucket);
        }

        if(c + a > A) {
            Bucket bucket = { A, b, c - (A - a)};
            q.push(bucket);
        } else {
            Bucket bucket = { a + c, b, 0};
            q.push(bucket);
        }

        if(c + b > B) {
            Bucket bucket = { a, B, c - (B - b)};
            q.push(bucket);
        } else {
            Bucket bucket = { a, b + c, 0};
            q.push(bucket);
        }
    }
}

int main() {
    scanf("%d %d %d", &A, &B, &C);
    memset(water, 0, sizeof(water));
    memset(visited, false, sizeof(visited));

    bfs();
    printWater();
}