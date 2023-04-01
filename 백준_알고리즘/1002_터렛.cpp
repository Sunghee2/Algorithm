#include <iostream>
#include <cmath>
using namespace std;

long long t, x1, x2, y1, y2, r1, r2;

int main() {
    cin >> t;
    for(int tc = 0; tc < t; tc++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if((x1 == x2) && (y1 == y2)) {
            if(r1 == r2) cout << "-1" << endl;
            else cout << 0 << endl;
        } else {
            double dist = sqrt((abs(x2 - x1) * abs(x2 - x1)) + (abs(y2 - y1) * abs(y2 - y1)));
            if(dist < (r1 + r2) && abs(r1 - r2) < dist) {
                cout << 2 << endl;
            } else if((r1 + r2) == dist || abs(r1 - r2) == dist) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
}