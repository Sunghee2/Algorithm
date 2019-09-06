#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<pair<int, int>> food_arr;
    for(int i = 0; i < food_times.size(); i++) {
        food_arr.push_back(make_pair(food_times[i], i + 1));
    }
    
    sort(food_arr.begin(), food_arr.end());
    
    long long height = 0;
    for(int i = 0; i < food_arr.size(); i++) {
        long long time = (food_arr[i].first - height) * (food_arr.size() - i);
        if(time == 0) continue;
        if(time <= k) {
            k -= time;
            height = food_arr[i].first;
        } else {
            k %= (food_arr.size() - i);
            sort(food_arr.begin() + i, food_arr.end(), comp);
            return food_arr[i + k].second;
        }
    }
    
    return -1;
}