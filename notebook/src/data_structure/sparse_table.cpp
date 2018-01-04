// input: A[0...N-1] and some queries where you need to compute function F
// over subarray [L; R]

// ST preprocessing time: O(N * log(N))
// ST answer query time: O(log(N))
// ST can be applied if and only if: A is immutable and F is associative
//
// https://e-maxx-eng.appspot.com/data_structures/sparse-table.html
// https://www.hackerearth.com/fr/practice/notes/sparse-table/

const int N = 1e5;
const int K = 17; // log2(N) + 1
const int NEUTRAL = 1e9 + 1; // (for any x) F(NEUTRAL, x) = F(x, NEUTRAL) = x

int n;
int a[N];
int dp[N][K];

// could be sum, min, max, gcd, etc.
int func(int a, int b);

void precompute(void)
{
    for(int i = 0; i < n; ++i)
        dp[i][0] = a[i];
    for(int j = 1; j <= K; ++j)
        for(int i = 0; i + (1 << j) <= n; ++i)
            dp[i][j] = func(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r)
{
    int ans = NEUTRAL;
    for(int j = K; j >= 0; --j) {
        if(l + (1 << j) - 1 <= r) {
            ans = func(ans, dp[l][j]);
            l += (1 << j);
        }
    }
    return ans;
}
