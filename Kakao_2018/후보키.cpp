#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> relation) {
    vector<int> candidate;
    for(int i = 1; i < 1 << relation[0].size(); i++) {
        map<string, int> m;
        bool flag = true;
        for(int j = 0; j < relation.size(); j++) {
            string str = "";
            for(int k = 0; k < relation[0].size(); k++) {
                if(i & (1 << k)) str += relation[j][k];
            }
            if(m[str] == 1) {
                flag = false;
                break;
            }
            m[str] = 1;
        }
        
        if(flag) {
            bool is_candidate = false;
            for(int j = 0; j < candidate.size(); j++) {
                if((i & candidate[j]) == candidate[j]) {
                    is_candidate = true;
                    break;
                }
            }
            
            if(!is_candidate) {
                candidate.push_back(i);
            }
        }
    }
    return candidate.size();
}