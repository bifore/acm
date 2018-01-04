// http://codeforces.com/blog/entry/18051
// this implementation even works for non-commutative functions and supports
// modification


const int T_MAX = 2 * N;

int n;
int t[T_MAX];

const int NEUTRAL = ???; // (for any x) F(NEUTRAL, x) = F(x, NEUTRAL) = x
int func(int a, int b);

void build(void)
{
    for(int i = n - 1; i > 0; --i)
        t[i] = func(t[2 * i], t[2 * i + 1]);
}

void modify(int p, int value)
{
    t[p += n] = value;
    while(p /= 2)
        t[p] = func(t[2 * p], t[2 * p + 1]);
}

// If you need interval [l;r) instead of [l;r], use 'r += n' (without the +1)
int query(int l, int r)
{
    int resl = NEUTRAL, resr = NEUTRAL;
    for(l += n, r += n + 1; l < r; l /= 2, r /= 2) {
        if(l&1) resl = func(resl, t[l++]);
        if(r&1) resr = func(t[--r], resr);
    }
    return func(resl, resr);
}
