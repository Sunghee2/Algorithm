#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int m_num, c_num, t, cur_time = 0;
int c_work[11];

typedef struct {
    int idx, time;
} Document;

int main(void) {
    cin >> m_num >> c_num;
    queue<Document> q;
    for(int i = 0; i < m_num; i++) {
        cin >> t;
        Document d = { i, t };
        q.push(d);
    }
    
    memset(c_work, -1, sizeof(c_work));
    
    while(1) {
        if(q.empty()) {
            bool is_all = true;
            for(int i = 0; i < c_num; i++) {
                if(c_work[i] != -1) is_all = false;
            }
            if(is_all) break;
        }
        
        for(int i = 0; i < c_num; i++) {
            if(c_work[i] == -1 || c_work[i] == cur_time) {
                if(q.empty()) {
                    c_work[i] = -1;
                    break;
                }
                Document d = q.front();
                c_work[i] = cur_time + d.time;
                q.pop();
            }
        }
        
        cur_time++;
    }
    
    cout << cur_time - 1 << endl;
}