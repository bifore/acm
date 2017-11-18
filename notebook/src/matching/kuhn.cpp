// Maximum matching in a bipartite graph O(N * M)
int n, m, k;
vector <int> edges[N_MAX + 1];
bool seen[NB_MAX + 1];
int r[NB_MAX + 1];

bool kuhn(int v)
{
    if(seen[v])
        return false;
    seen[v] = true;

    for(int i = 0; i < edges[v].size(); ++i) {
        int u = edges[v][i];
        if(r[u] == -1 || kuhn(r[u])) {
            r[u] = v;
            return true;
        }
    }
    return false;
}

void max_match(void)
{
    for(i = 0; i <= n; ++i)
        r[i] = -1;

    int ans = 0;
    for(i = 1; i <= n; ++i) {
        for(j = 0; j <= n; ++j)
            seen[j] = false;
        if(kuhn(i))
            ++ans;
    }

    printf("%d\n", ans);
    for(i = 1; i <= n; ++i)
        if(r[i] != -1)
            printf("%d %d\n", r[i], i);
}
