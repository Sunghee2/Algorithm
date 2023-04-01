#include <iostream>
using namespace std;

int h, nh, m, nm;

int main() {
    cin >> h >> m;

    int tmp = (h == 0)? (24 * 60) + m - 45 : (h * 60) + m - 45;
    nh = tmp / 60;
    nm = tmp - (nh * 60);
    nh = nh == 24 ? 0 : nh;
    cout <<nh << " " << nm << endl; 
}