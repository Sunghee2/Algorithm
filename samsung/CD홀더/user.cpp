/// *** user.cpp ***

const int LM = 100005;
const int SIZE = (1 << 18); // tree size
int N, H, D, que[LM], chk[LM], fr, re;

struct Data {
    int max, min;
} tree[SIZE];

int Max(int x, int y) {return x > y? x : y;}
int Min(int x, int y) {return x < y? x : y;}

void update(int node, int s, int e, int id, int type) {
    if(s == e) {
        if(type) tree[node] = { id, id }; // insert
        else tree[node] = { -1, N }; //delete - 최대값 -1설정, 최소값 N 설정
        return;
    } 

    int lch = node * 2, rch = lch + 1, m = (s + e) / 2;
    if(id <= m) update(lch, s, m, id, type);
    else update(rch, m + 1, e, id, type);
    tree[node] = { Max(tree[lch].max, tree[rch].max), Min(tree[lch].min, tree[rch].min) };
} 

int maxfind(int node, int s, int e, int qs, int qe) {
    if(qe < s || e < qs) return -1;
    if(qs <= s && e <= qe) return tree[node].max;

    int lch = node * 2, rch = lch + 1, m = (s + e) / 2;
    return Max(maxfind(lch, s, m, qs, qe), maxfind(rch, m + 1, e, qs, qe));
}

int minfind(int node, int s, int e, int qs, int qe)
{
    if (qe < s || e < qs)
        return N;
    if (qs <= s && e <= qe)
        return tree[node].min;

    int lch = node * 2, rch = lch + 1, m = (s + e) / 2;
    return Min(minfind(lch, s, m, qs, qe), minfind(rch, m + 1, e, qs, qe));
}

void init(int holder_size, int head)
{
    N = holder_size, H = head, D = 0; // 방향 : 왼쪽 0, 오른쪽 1
    fr = re = 0;
    for(int i = 0; i <= N; i++) chk[i] = 0;
    for(int i = 0; i < SIZE; i++) tree[i] = { -1, N }; 
}
void insert(int holder)
{
    chk[holder] = 1;
    que[re++] = holder;
    update(1, 0, N - 1, holder, 1);
}

int deleteId(int id)
{
    chk[id] = 0;
    update(1, 0, N - 1, id, 0);
    H = id; // head 옮겨줘야함
    return id;
}

int first()
{
    while(chk[que[fr]] == 0) fr++; // 삭제된 노드인지 확인
    int id = que[fr++];
    return deleteId(id);
}

int near()
{
    int lid = maxfind(1, 0, N - 1, 0, H); // 0 ~ head 범위까지 큰 것
    int id = minfind(1, 0, N - 1, H, N - 1); // head ~ N -1 까지 작은 것
    if(id == N || (lid >= 0 && H - lid <= id - H)) id = lid; // right id가 범위를 벗어난 경위, lid가 존재하고 더 가까운 경우
    return deleteId(id);
}

int forward()
{
    int id;
    if(D == 0) id = maxfind(1, 0, N - 1, 0, H); // 왼쪽
    else id = minfind(1, 0, N - 1, H, N - 1); // 오른쪽

    // 방향 바꿈
    if(id < 0 || id >= N) { 
        D = 1 - D;
        if (D == 0)
            id = maxfind(1, 0, N - 1, 0, H);
        else
            id = minfind(1, 0, N - 1, H, N - 1);
    }
    return deleteId(id);
}
int left()
{
    int id = maxfind(1, 0, N - 1, 0, H);
    if(id < 0)
        id = maxfind(1, 0, N - 1, 0, N - 1); // H ~ N - 1에서 찾으면 되지만 맨 처음부터 찾으면 속도가 더 빠름
    return deleteId(id);
}

int right()
{
    int id = minfind(1, 0, N - 1, H, N - 1);
    if(id >= N)
        id = minfind(1, 0, N - 1, 0, N - 1);
    return deleteId(id);
}