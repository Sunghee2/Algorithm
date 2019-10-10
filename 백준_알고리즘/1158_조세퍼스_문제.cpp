#include <iostream>
#include <vector>
using namespace std;

int n, k, cur_position = 0;
vector<int> arr;

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        arr.push_back(i + 1);
    }

    cout << "<";
    while(arr.size() > 0) {
        if(cur_position + (k - 1) < arr.size()) {
            cout << arr[cur_position + (k - 1)];
            cur_position += (k - 1);
            arr.erase(arr.begin() + cur_position);
        } else {
            cur_position = ((k - 1) + cur_position) % arr.size();
            cout << arr[cur_position];
            arr.erase(arr.begin() + cur_position);
        }
        if(arr.size() > 0) cout << ", ";
    }
    cout << ">";
}


/**
 * 1 2 3 4 5 6 7
 * **/