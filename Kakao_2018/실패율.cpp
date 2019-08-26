#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> arr;
    
    for(int i = 1; i <= N; i++) {
        int m = 0, d = 0;
        for(int j = 0; j < stages.size(); j++) {
            if(i <= stages[j]) d++;
            if(i == stages[j]) m++;
        }
        if(m == 0) {
            arr.push_back(make_pair(i, 0));
            continue;
        }
        arr.push_back(make_pair(i, m / (double) d));
    }
    
    sort(arr.begin(), arr.end(), compare);
    
    for(int i = 0; i < arr.size(); i++) {
        answer.push_back(arr[i].first);
    }
    
    return answer;
}