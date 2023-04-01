#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000000001
using namespace std;

int n, k, f;
vector<bool> visited(MAX, false);

int main() {
    cin >> n >> k;

    queue<int> q;
    for(int i = 0; i < n; i++) {
        cin >> f;
        if(!visited[f]) {
            if(q.size() < k) {
                q.push(f);
                visited[f] = true;
            } else {
                int num = q.front();
                q.pop();
                visited[num] = false;
                q.push(f);
                visited[f] = true;
            }
        }
    }

    cout << q.size() << endl;
    vector<int> ret;
    while(!q.empty()) {
        ret.push_back(q.front());
        q.pop();
    }

    for(int i = ret.size() - 1; i >= 0; i--) {
        cout << ret[i] << " ";
    }
}