#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int num, s, e;

typedef struct {
    int in, out;
} Person;

bool comp(Person a, Person b) {
    if(a.in == b.in) return a.out < b.out;
    return a.in < b.in;
}

int main(void) {
    cin >> num;
    
    vector<Person> people;
    queue<Person> q;
    vector<int> toilet;
    for(int i = 0; i < num; i++) {
        cin >> s >> e;
        Person p = {s, e};
        people.push_back(p);
    }
    
    sort(people.begin(), people.end(), comp);
    
    for(int i = 0; i < num; i++) {
        if(people[i].in == 0) {
            toilet.push_back(people[i].out);
            people.erase(people.begin());
        } else break;
    }
    
    while(people.size() > 0) {
        for(int i = 0; i < people.size(); i++) {
            bool is_in = false;
            for(int j = 0; j < toilet.size(); j++) {
                if(toilet[j] <= people[i].in) {
                    toilet[j] = people[i].out;
                    is_in = true;
                }
            }
            if(!is_in) toilet.push_back(people[i].out);
            people.erase(people.begin());
        }
    }
    
    cout << toilet.size() << endl;
}