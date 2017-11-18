// Maximum flow O(N^2 * M)
struct Edge {
    int u, v;
    int c;
    int f;
    int rev;
};

int n, m;
vector <Edge> edges[MAX_N + 1];
int ptr[MAX_N + 1];
int dist[MAX_N + 1];

void add_edge(int u, int v, int c)
{
    Edge e1 = {u, v, c, 0, (int)edges[v].size()};
    Edge e2 = {v, u, 0, 0, (int)edges[u].size()};
    edges[u].pb(e1);
    edges[v].pb(e2);
}

bool bfs(void)
{
    queue <int> q;
    int i;
    for(i = 1; i <= n; ++i)
        dist[i] = -1;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(i = 0; i < edges[cur].size(); ++i) {
            Edge e = edges[cur][i];
            if(e.f == e.c || dist[e.v] != -1)
                continue;
            dist[e.v] = dist[cur] + 1;
            q.push(e.v);
        }
    }
    return (dist[n] != -1);
}

int dfs(int v, int m)
{
    if(v == n)
        return m;
    if(m == 0)
        return 0;

    for(; ptr[v] < edges[v].size(); ++ptr[v]) {
        Edge& e = edges[v][ptr[v]];
        if(dist[e.u] + 1 != dist[e.v])
            continue;
        int r = dfs(e.v, min(m, e.c - e.f));
        if(r != 0) {
            e.f += r;
            edges[e.v][e.rev].f -= r;
            return r;
        }
    }
    return 0;
}

int dinic(void)
{
    int ans = 0;
    int i;
    while(bfs()) {
        for(i = 0; i <= n; ++i)
            ptr[i] = 0;
        int x;
        while((x = dfs(1, INF)))
            ans += x;
    }
    return ans;
}
