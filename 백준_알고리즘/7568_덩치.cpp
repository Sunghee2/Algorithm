#include <iostream>
#include <vector>
using namespace std;

vector<int> check(vector<pair<int, int> > &people, int people_num) {
    vector<int> result(people_num);
    for(int i = 0; i < people_num; i++) {
        int num = 0;
        for(int j = 0; j < people_num; j++) {
            if(i != j && people[i].first < people[j].first && people[i].second < people[j].second) {
                num++;
            }
        }
        result[i] = num + 1;
    }

    return result;
}

int main() {
    int people_num, height, weight;
    cin >> people_num;

    vector<pair<int, int> > people;
    for(int i = 0; i < people_num; i++) {
        cin >> height >> weight;
        people.push_back(make_pair(height, weight));
    }

    vector<int> result(people_num);
    result = check(people, people_num);

    for(int i = 0; i < people_num; i++) {
        cout << result[i] << " ";
    }
}