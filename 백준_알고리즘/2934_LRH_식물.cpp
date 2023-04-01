#include <iostream>
using namespace std;

int main() {
    int day, left, right, park;
    scanf("%d", &day);

    while(day--) {
        int flower_num = 0;
        scanf("%d %d", &left, &right);

        for(int i = left; i <= right; i++) {
            if((park & (1 << i)) && ((i == left) || (i == right))) {
                cout << "flower " << i << endl;
                flower_num++;
                park -= (1 << i);
            } else if((left < i) && (i < right)) {
                cout << "make " << i << endl;
                park |= (1 << i);
            }
        }

        printf("%d\n", flower_num);
    }
}