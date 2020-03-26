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

<br/>

### 자주 검색하는 것

1. string 입력  +  split

   `#include <string>` 쓰거나 아니면 char array로 받음. `scanf()`보다 그냥 `cin >> str` 으로 하는 게 훨씬 편함..

   한글자씩 받아도 `scanf("%s", arr)` char array로 바로 받을 수 있음.  

   > 대소문자 아스키코드 32 차이남. ex) 소 -> 대 ch-32

   `scanf("%c")` 여러 개 받고 엔터가 있어서 중간에 하나씩 못받고 그러면 `scanf("%c ")` 공백을 넣어주면 개행문자(스페이스, 엔터)를 무시해주는 역할을 함.

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

