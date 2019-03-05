#include <cstdio>

int main() {
    // 입력
    int n1, n2, second;
    scanf("%d %d\n", &n1, &n2);

    char ant[n1 + n2];
    bool chk[n1 + n2];
    for(int i = n1 - 1; i >= 0; i--) {
        scanf("%c ", &ant[i]);
        chk[i] = true;
    }
    for(int i = n1; i < n1 + n2; i++) {
        scanf("%c ", &ant[i]);
        chk[i] = false;
    }
    scanf("\n%d", &second);

    // 점프
    while(second--) {
        for(int i = 0; i < n1 + n2 - 1;) {
            if((chk[i] == true) && (chk[i + 1] == false)) {
                char temp = ant[i];
                ant[i] = ant[i + 1];
                ant[i + 1] = temp;
                chk[i] = false;
                chk[i + 1] = true;
                i += 2;
            } else {
                i++;
            }
        }
    }

    // 출력
    for(int i = 0; i < n1 + n2; i++) {
        printf("%c", ant[i]);
    }
}


/**
 * ABC / DEF
 * CBADEF
 * 1. CBDAEF
 * 2. CDBEAF
 * 3. DCEBFA
 * 4. DECFBA
 * 5. DEFCBA
 * 
 * 한글자씩 입력받으면서 bool array도 만들고 왼쪽에 있는 것은 true, 오른쪽에 있는 것은 false로 지정함
 * 1초마다 한번씩 보면서 true, false를 확인하게 되는데 i번째가 true이고 i+1번째가 false면 서로 반대방향으로 있는 개미가 있으므로 점프를 해야됨
 * 그래서 24번째줄과 같이 swap을 해주고 점프를 했으니 bool array도 고쳐줌.
 * 
 * **/