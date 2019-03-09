#include <cstdio>
#include <string>

int main() {
    int testcase, date, year, month, day;
    scanf("%d", &testcase);

    for(int i = 1; i <= testcase; i++) {
        scanf("%d", &date);
        day = (date % 10) + (((date / 10) % 10) * 10);
        month = ((date / 100) % 10) + (((date / 1000) % 10) * 10);
        year = ((date / 10000) % 10) + (((date / 100000) % 10) * 10) + (((date / 1000000) % 10) * 100) + (((date / 10000000) % 10) * 1000);
        if((1 <= month) && (month <= 12)) {
            if((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) {
                if(day <= 31) {
                    printf("#%d %04d/%02d/%02d\n", i, year, month, day);
                } else {
                    printf("#%d -1\n", i);
                }
            } else if((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
                if(day <= 30) {
                    printf("#%d %04d/%02d/%02d\n", i, year, month, day);                    
                } else {
                    printf("#%d -1\n", i);
                }
            } else {
                if(day <= 28) {
                    printf("#%d %04d/%02d/%02d\n", i, year, month, day);
                } else {
                    printf("#%d -1\n", i);
                }
            }
        } else {
            printf("#%d -1\n", i);
        }
    }
}