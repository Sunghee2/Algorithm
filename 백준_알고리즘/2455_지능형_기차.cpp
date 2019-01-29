#include <iostream>
using namespace std;

int main() {
    int loop_num = 4, in, out, people = 0, max = 0;

    while(loop_num-- > 0) {
        scanf("%d %d", &out, &in);
        people = people + in - out;
        if(people > max) max = people;
    }

    printf("%d\n", max);
}