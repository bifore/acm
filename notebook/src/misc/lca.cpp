// https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/
// TESTED ON http://www.spoj.com/problems/LCA/

// <f(N), g(N)> f: preprocessing time, g: query time


// METHOD 1: SQRT decomposition <O(N), O(sqrt(N))>
void calc_depth(int node, int d)
{
    depth[node] = d;
    for(auto v : edges[node])
        calc_depth(v, d + 1);
}

void dfs(int node)
{
    if(depth[node] < SQRT)
        ancestor[node] = root;
    else if(depth[node] % SQRT == 0)
        ancestor[node] = parent[node];
    else
        ancestor[node] = ancestor[parent[node]];

    for(auto v : edges[node])
        dfs(v);
}

void lca_sqrt_precompute(void)
{
    calc_depth(root, 0);
    dfs(root);
}

int lca_sqrt_query(int u, int v)
{
    while(ancestor[u] != ancestor[v]) {
        if(depth[u] > depth[v])
            u = ancestor[u];
        else
            v = ancestor[v];
    }

    while(u != v) {
        if(depth[u] > depth[v])
            u = parent[u];
        else
            v = parent[v];
    }

    return u;
}

// METHOD 2: DP/Sparse table <O(N * log(N)), O(log(N))>
void lca_dp_precompute(void)
{
    calc_depth(root, 0);

    foru(i, 1, n)
        for(int j = 0; (1 << j) <= n; ++j)
            dp[i][j] = -1;
    foru(i, 1, n)
        dp[i][0] = parent[i];

    for(int j = 1; (1 << j) <= n; ++j)
        foru(i, 1, n)
            if(dp[i][j - 1] != -1)
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
}

int lca_dp_query(int u, int v)
{
    if(depth[u] < depth[v])
        swap(u, v);

    ford(i, LOG_MAX, 0)
        if(depth[u] - (1 << i) >= depth[v])
            u = dp[u][i];
    if(u == v)
        return u;
    ford(i, LOG_MAX, 0)
        if(dp[u][i] != -1 && dp[u][i] != dp[v][i])
            u = dp[u][i], v = dp[v][i];
    return parent[u];
}
