#include <iostream>
using namespace std;

int main() {
    int testcase;
    long n;
    cin >> testcase;

    for(int i = 1; i <= testcase; i++) {
        cin >> n;
        long s1 = (n * (n + 1)) / 2;
        long s3 = s1 * 2;
        long s2 = s3 - n;
        printf("#%d %ld %ld %ld\n", i, s1, s2, s3);
    }
}

/**
 * 범위때문에 시간을 너무 쓴 문제ㅠㅠ
 * 입력받는 것도 long으로.. -> 왜지..? 10의 9승이면 입력받는 n은 int 가능한거아닌가???
 * 
 * 원래 처음 작성한 건 아래와 같은데 위와 같이 범위문제로 버려진....(아래에는 long으로 고쳐놓음)
 * 
 * #include <iostream>
using namespace std;

int main() {
    int testcase;
    long n;
    cin >> testcase;

    for(int i = 1; i <= testcase; i++) {
        cin >> n;
        long s1 = n == 1? 1 : (1 + n) * (n / 2);
        if((n % 2 == 1) && (n != 1)) s1 += (n / 2) + 1;
        long s2 = (1 + ((2 * n) - 1)) * (n / 2);
        if(n % 2 == 1) s2 += n;
        long s3 = (2 + (2 * n)) * (n / 2);
        if(n % 2 == 1) s3 += n + 1;
        printf("#%d %ld %ld %ld\n", i, s1, s2, s3);
    }
}
 * **/