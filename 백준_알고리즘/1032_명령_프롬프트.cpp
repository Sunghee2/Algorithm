#include <iostream>
#include <string>
using namespace std;

int n, max_length = 0;
string file_name = "", result = "";
string arr[51];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        max_length = max_length < arr[i].size() ? arr[i].size() : max_length;
    }

    int start_idx = -1;
    char c = 0;
    bool type_done = false, is_all = true;

    for(int i = max_length - 1; i >= 0; i--) {

        bool is_same = true;
        if(arr[0].size() > i) {
            c = arr[0].at(i);
            start_idx = 0;
        }
        for(int j = 0; j < n; j++) {
            if(arr[j].size() <= i) continue;
            if(c != 0) {
                if(c != arr[j].at(i)) is_same = false;
            } else {
                c = arr[j].at(i);
                start_idx = j;
            }
        }

        if(!type_done) {
            if(!is_same) result = "?" + result;
            else if(start_idx >= 0) {
                result = arr[start_idx].at(i) + result;
                if(c == '.') type_done = true;
            }
        } else if(type_done) {
            if(is_same) file_name = arr[start_idx].at(i) + file_name;
            else file_name = "?" + file_name;
        }

        c = 0;
    }

    if(file_name.size() > 0) {
        for(int i = 0; i < file_name.size(); i++) {
            if(file_name.at(i) != '?') {
                is_all = false; 
                break;
            }
        }

        if(is_all) {
            result = "*" + result;
        } else {
            result = file_name + result;
        }
    }

    cout << result << endl;
}