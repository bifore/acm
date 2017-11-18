// Minimum cost maximum flow
struct Edge {
    lli u, v;
    lli c, p;
    lli f;
    lli rev;
};

lli n, m;
vector <Edge> edges[N_MAX + 1];

void add_edge(lli u, lli v, lli c, lli p)
{
    Edge e1 = {u, v, c, p, 0, (lli)edges[v].size()};
    Edge e2 = {v, u, 0, -p, 0, (lli)edges[u].size()};
    edges[u].pb(e1);
    edges[v].pb(e2);
}

int min_cost_max_flow(void)
{
    lli ans = 0;
    while(true) {
        lli d[n + 1];
        ii from[n + 1];
        for(i = 0; i <= n; ++i) {
            d[i] = INF;
            from[i] = mp(-1, -1);
        }
        d[1] = 0;
        from[1] = mp(1, 1);
        // Bellman-ford (assuming no negative cycle)
        bool changed = true;
        while(changed) {
            changed = false;
            for(i = 1; i <= n; ++i) {
                if(d[i] == INF)
                    continue;
                for(j = 0; j < edges[i].size(); ++j) {
                    Edge e = edges[i][j];
                    if(e.c > e.f && d[e.v] > d[e.u] + e.p) {
                        d[e.v] = d[e.u] + e.p;
                        from[e.v] = mp(i, j);
                        changed = true;
                    }
                }
            }
        }

        if(d[n] == INF)
            return ans;

        lli u = n;
        lli min_flow = INF;
        while(u != 1) {
            Edge e = edges[from[u].fi][from[u].se];
            min_flow = min(min_flow, e.c - e.f);
            u = e.u;
        }

        u = n;
        while(u != 1) {
            Edge &e = edges[from[u].fi][from[u].se];
            e.f += min_flow;
            edges[e.v][e.rev].f -= min_flow;
            u = e.u;
        }

        ans += d[n] * min_flow;
    }
    return -1;
}
