// https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/
// TESTED ON: http://www.spoj.com/problems/RMQSQ/

// <f(N), g(N)> f: preprocessing time, g: query time

// Dynamic Programming
// <O(N^2), O(1)> with O(N^2) memory
void rmq_dp(void)
{
	int dp[n + 1][n + 1];
	for(int i = 0; i < n; ++i)
		dp[i][i] = a[i];
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
			dp[i][j] = min(dp[i][j - 1], a[j]);
}

// SQRT Decomposition
// <O(N), O(sqrt(N))>
// https://e-maxx-eng.appspot.com/data_structures/sqrt_decomposition.html
void rmq_sqrt_preprocessing(void)
{
    int len = (int)(sqrt((double)(n)) + 1);
    vector<int> b(len, INF);
    for(int i = 0; i < n; ++i)
        b[i / len] = min(b[i / len], a[i]);
}

// First method
int rmq_sqrt_query(int l, int r)
{
	// [l; r]
	int ans = INF;
	while(l <= r) {
		// Whole block
		if(l % len == 0 && l + len - 1 <= r) {
			ans = min(ans, b[l / len]);
			l += len;
		}
		else {
			ans = min(ans, a[l]);
			++l;
		}
	}
	return ans;
}

// Second Method (without so many divisions)
int rmq_sqrt_query2(int l, int r)
{
	int ans = INF;
	int c_l = l / len;
	int c_r = r / len;
	if(c_l == c_r) {
		for(int j = l; j <= r; ++j)
			ans = min(ans, a[j]);
	}
	else {
		int end = (c_l + 1) * len - 1;
		for(int j = l; j <= end; ++j)
			ans = min(ans, a[j]);
		for(int j = c_l + 1; j <= c_r - 1; ++j)
			ans = min(ans, b[j]);
		for(int j = c_r * len; j <= r; ++j)
			ans = min(ans, a[j]);
	}
	return ans;
}
