#include <iostream>
#include <vector>
#define MAX_LEN 51
using namespace std;

int n, m, num, cnt = 0;
bool is_front;
vector<int> v;

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        v.push_back(i);
    }

    while(m--) {
        cin >> num;

        for(int i = 0; i < n; i++) {
            if(v[i] == num) {
                is_front = true;
                break;
            } else if(v[n - i - 1] == num) {
                is_front = false;
                break;
            }
        }

        if(is_front) {
            while(1) {
                // 왼쪽으로 이동
                int tmp = v.front();
                v.erase(v.begin());

                if(tmp == num) break;

                v.push_back(tmp);
                cnt++;
            }
        } else {
            while(1) {
                //오른쪽으로 이동
                int tmp = v.back();
                v.pop_back();

                cnt++;
                if(tmp == num) break;
                v.insert(v.begin(), tmp);
            }
        }

        n--;

    }

    cout << cnt << endl;
}