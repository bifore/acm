// Maximum flow O(M^2 * log(MAX_CAP))
struct Edge {
    int u, v;
    int c;
    int f;
    int rev;
};

int n, m;
vector <Edge> edges[MAX_N + 1];
bool seen[MAX_N + 1];

void add_edge(int u, int v, int c)
{
    Edge e1 = {u, v, c, 0, (int)edges[v].size()};
    Edge e2 = {v, u, 0, 0, (int)edges[u].size()};
    edges[u].pb(e1);
    edges[v].pb(e2);
}

int dfs(int v, int c, int m)
{
    if(v == n)
        return m;
    if(seen[v])
        return 0;
    seen[v] = true;
    for(int i = 0; i < edges[v].size(); ++i) {
        Edge &e = edges[v][i];
        if(e.c - e.f < c)
            continue;
        int r = dfs(e.v, c, min(m, e.c - e.f));
        if(r != 0) {
            e.f += r;
            edges[e.v][e.rev].f -= r;
            return r;
        }
    }
    return 0;
}

int scaling(void)
{
    int ans = 0;
    int M = (1 << 29);
    for(i = 29; i >= 0; --i) {
        while(true) {
            for(j = 1; j <= n; ++j)
                seen[j] = false;
            int res = dfs(1, M, INF);
            if(!res)
                break;
            ans += res;
        }
        M /= 2;
    }
    return ans;
}
