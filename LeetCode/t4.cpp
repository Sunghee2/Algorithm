#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, input, ret = -1;
    cin >> n;
    
    vector<int> seats;
    for(int i = 0; i < n; i++) {
        cin >> input;
        seats.push_back(input);
    }
    
    for(int i = 0; i < n; i++) {
        int diff = 2147483647;
        if(seats[i] == 0) {
            for(int j = i; j >= 0; j--) {
                if(seats[j] == 1)  {
                    diff = diff > (i - j)? i - j : diff;
                    break;
                }
            }
            
            for(int j = i; j < n; j++) {
                if(seats[j] == 1)  {
                    diff = diff > (j - i)? j - i : diff;
                    break;
                }
            }
            
            if(diff != 2147483647) ret = ret < diff? diff : ret;
        }
    }
    
    cout << ret << endl;
    
}