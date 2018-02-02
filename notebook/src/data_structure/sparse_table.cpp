// input: A[0...N-1] and some queries where you need to compute function F
// over subarray [L; R]

// ST preprocessing time: O(N * log(N))
// ST answer query time: O(log(N))
// ST can be applied if and only if: A is immutable and F is associative
//
// https://e-maxx-eng.appspot.com/data_structures/sparse-table.html
// https://www.hackerearth.com/fr/practice/notes/sparse-table/

const int K = ???; // K = log2(N) + 1

int n;
int a[N];
int dp[N][K];

const int NEUTRAL = ???; // (for any x) F(NEUTRAL, x) = F(x, NEUTRAL) = x
// could be sum, min, max, gcd, etc.
int func(int a, int b);

void precompute(void)
{
    forn(i, n)
        dp[i][0] = a[i];
    foru(j, 1, K)
        for(int i = 0; i + (1 << j) <= n; ++i)
            dp[i][j] = func(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r)
{
    int ans = NEUTRAL;
    ford(j, K, 0) {
        if(l + (1 << j) - 1 <= r) {
            ans = func(ans, dp[l][j]);
            l += (1 << j);
        }
    }
    return ans;
}
