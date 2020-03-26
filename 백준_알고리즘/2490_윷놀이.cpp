#include <iostream>
using namespace std;

int main() {
    for(int t = 0; t < 3; t++) {
        int sum = 0, num;
        for(int i = 0; i < 4; i++) {
            cin >> num;
            sum += num;
        }

        if(sum == 1) {
            cout << "C" << endl;
        } else if(sum == 2) {
            cout << "B" << endl;
        } else if(sum == 3) {
            cout << "A" << endl;
        } else if(sum == 4) {
            cout << "E" << endl;
        } else {
            cout << "D" << endl;
        }
    }
}