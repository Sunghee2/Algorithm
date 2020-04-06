# Algorithm

Problem solving with **C++**

> [java로 푼 알고리즘](https://github.com/Sunghee2/BOJ-Algorithm-Java)

### 자주 하는 실수

1. 문제 꼼꼼하게 읽기

   > 정말 자주(거의 매일..)하는 실수..  + 문제 분할해서 푸는 것 좋은 방법임.
   >
   > 1) 문제 이해
   >
   > 2) 입력 범위 항상 체크

2. 산술 오버플로우

   > 최소, 최대일 경우 테스트 꼭 해보기
   >
   > short (2 byte) = 2<sup>15</sup> - 1 (= 32767)
   >
   > int (4 byte) = 2<sup>31</sup> - 1 (= 2.1 X 10<sup>9</sup> = 21억)
   >
   > float (4 byte)
   >
   > long long(8 byte) = 2<sup>63</sup> - 1 (= 9.2 X 10<sup>18</sup>)
   >
   > double (8 byte)

3. for문 여러개 일 경우 - 변수를 섞어씀..

   ```java
   for(int i = 0; i < n; i++) {
       for(int j = 0; j < m; i++) { // i++ -> j++
       }
   }
   ```

4. 평균구할 때 double sum으로 하기 ( + 0 나눌 때 결과가 0이 아니라 이상한 값 나옴 주의!)

   > 반올림 round()함수. (include <math.h>)

5. 초기화 너무너무 중요

   > 특히 2차원 배열 `memset(visited, 0, sizeof(visited))` 주의
   >
   > -> cstring , std

6. break, return 섞어 씀 자꾸..
7. 시험볼 때 11인지 14인지 확인하기..진짜 문법때문에 힘들었음ㅠ
8. x, y (or m, n / i, j) 방향 체크!!!!

<br/>

### 자주 검색하는 것

1. string 입력  +  split

   `#include <string>` 쓰거나 아니면 char array로 받음. `scanf()`보다 그냥 `cin >> str` 으로 하는 게 훨씬 편함..

   한글자씩 받아도 `scanf("%s", arr)` char array로 바로 받을 수 있음.  

   > 대소문자 아스키코드 32 차이남. ex) 소 -> 대 ch-32

   `scanf("%c")` 여러 개 받고 엔터가 있어서 중간에 하나씩 못받고 그러면 `scanf("%c ")` 공백을 넣어주면 개행문자(스페이스, 엔터)를 무시해주는 역할을 함.

   > 공백 포함된 입력 받을 때는
   >
   > ```c++
   > string s;
   > getline(cin, s);
   > ```

2. type 변환

   - int -> string : `to_string(num)`

   - string -> char : `str.c_str()`

   - char -> int : `atoi(char)`

     > double :  `atof`
     >
     > long : `atol`

3. 조합

   - next_permutation / prev_permutation
   - 재귀

4. regex

5. 비트연산자

   - `>>`
   - `<<`

<br/>

### 참고

1. Set

   > set : 중복x
   >
   > multiset : 중복o
   
2. 시간 복잡도

   |   N 크기    |     시간복잡도      |
   | :---------: | :-----------------: |
   |    ~ 11     |        O(N!)        |
   |    ~ 25     |  O(2<sup>N</sup>)   |
   |    ~ 100    |  O(N<sup>4</sup>)   |
   |    ~ 500    |  O(N<sup>3</sup>)   |
   |   ~ 3000    | O(N<sup>2</sup>lgN) |
   |   ~ 5000    |  O(N<sup>2</sup>)   |
   | ~ 1,000,000 |       O(NlgN)       |
   | ~10,000,000 |        O(N)         |
   |   그 이상   |    O(lgN), O(1)     |

3. 공간 복잡도

   512MB = 1.2억개 int(4byte)

4. 실수

   1. 실수 저장 / 연산 과정에서 반드시 오차가 발생할 수 밖에 없음

      ```c++
      0.1 + 0.1 == 0.2 // false
      ```

      > double 상대 오차 10<sup>-15</sup>

   2. double에 long long 정수 담으면 x, int는 O

      > double 유효숫자는 15자리 / long long은 최대 19자리

   3. 실수 비교

      ```c++
      a == b // X
      abs(a - b) < 1e-12 // O
      ```

5. reference

   원본 바꾸는 방법

   ```c++
   // pointer
   void swap(int* a, int* b) {
   	int tmp = *a;
     *a = *b;
     *b = tmp;
   }
   ```

   ```c++
   // reference
   void swap(int& a, int& b) {
   	int tmp = a;
     a = b;
     b = tmp;
   }
   ```

   > vector 같은 stl의 경우 함수 인자로 보낼 때 복사본을 만들어서 보내 원본에 영향을 주지 않음.
   >
   > ```c++
   > bool comp(vector<int> v1, vector<int> v2, int idx) { return v1[idx] > v2[idx]; }
   > ```
   >
   > 그래서 위는 O(1) 이 아닌 O(N). (복사해서 보내기 때문) --> reference면 O(1)

