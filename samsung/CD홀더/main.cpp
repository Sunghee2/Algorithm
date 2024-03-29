/// *** main.cpp ***
#include <stdio.h>
enum COMMAND
{
    CMD_INSERT = 0,
    CMD_FIRST = 1,
    CMD_NEAR = 2,
    CMD_FORWARD = 3,
    CMD_LEFT = 4,
    CMD_RIGHT = 5
};
extern void init(int holder_size, int head);
extern void insert(int holder);
extern int first();
extern int near();
extern int forward();
extern int left();
extern int right();
static const int MAX = 100000;
static int holder_size; // 입력받는 홀더 사이즈
static int holder_head; // 입력받는 헤드 위치
static int query_size; // 쿼리 개수 
static int in_size; // 삽입 개수
static int ans_size; // 삭제 개수
static int query[MAX]; // 쿼리 종류(0은 삽입, 나머지는 삭제)
static int in[MAX]; // 삽입 홀더번호 (쿼리가 0인 경우)
static int ans[MAX]; // 삭제 홀더번호
static bool holder[MAX]; // 해당 칸에 CD 존재 여부

static void input_data()
{
    scanf("%d %d", &holder_size, &holder_head);
    scanf("%d", &query_size);
    for (register int i = 0; i < query_size; ++i)
        scanf("%d", &query[i]);
    scanf("%d", &in_size);
    for (register int i = 0; i < in_size; ++i)
        scanf("%d", &in[i]);
    scanf("%d", &ans_size);
    for (register int i = 0; i < ans_size; ++i)
        scanf("%d", &ans[i]);
}
static int run()
{
    int in_cnt = 0, ans_cnt = 0;
    int user_ans = 0;
    for (register int i = 0; i < holder_size; ++i)
        holder[i] = false;
    for (int query_cnt = 0; query_cnt < query_size; query_cnt++)
    {
        if (query[query_cnt] == CMD_INSERT)
        {
            holder[in[in_cnt]] = true;
            insert(in[in_cnt]);
            in_cnt++;
        }
        else
        {
            switch (query[query_cnt])
            {
            case CMD_FIRST: // 1
                user_ans = first();
                break;
            case CMD_NEAR: // 2
                user_ans = near();
                break;
            case CMD_FORWARD: // 3
                user_ans = forward();
                break;
            case CMD_LEFT: // 4
                user_ans = left();
                break;
            case CMD_RIGHT: // 5
                user_ans = right();
                break;
            }
            if (user_ans != ans[ans_cnt])
                return 0;
            holder[ans[ans_cnt]] = false;
            ans_cnt++;
        }
    }
    return 100;
}
int main()
{
    setbuf(stdout, NULL);
    /// freopen("input.txt", "r", stdin);
    int total_score = 0, TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; ++tc)
    {
        input_data();
        init(holder_size, holder_head);
        int score = run();
        printf("#%d %d\n", tc, score);
        total_score += score;
    }
    printf("Total score: %d\n", total_score);
    return 0;
}