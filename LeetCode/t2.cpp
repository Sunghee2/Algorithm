#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int k, size;
vector<int> number, result;

int main(void) {
    string input, n;
    getline(cin, input);
    cin >> k;
    
    stringstream ss(input);
    while(ss >> n) {
        number.push_back(atoi(n.c_str()));
    }

    sort(number.begin(), number.end());
    
    do {
        string num = "";
        for(int i = 0; i < number.size(); i++) {
            num += to_string(number[i]);
        }
        if(num != "") {
            result.push_back(atoi(num.c_str()));
        }
    } while(next_permutation(number.begin(), number.end()));
    
    sort(result.begin(), result.end());
    
    cout << result[k - 1] << endl;
    
    return 0;
}