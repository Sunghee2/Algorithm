#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    
    for(int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        string str, id, name;
        ss >> str;
        if(str != "Leave") {
            ss >> id;
            ss >> name;
            m[id] = name;
        }
        ss.clear();
    }
    
    for(int i = 0; i < record.size(); i++) {
        stringstream ss(record[i]);
        string str, id;
        ss >> str;
        if(str == "Enter") {
            ss >> id;
            answer.push_back(m[id] + "님이 들어왔습니다.");
        } else if(str == "Leave") {
            ss >> id;
            answer.push_back(m[id] + "님이 나갔습니다.");
        } 
        ss.clear();
    }

    return answer;
}