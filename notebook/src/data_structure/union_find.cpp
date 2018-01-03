const int MAX_N = 1000;

int parent[MAX_N + 5];
int rank[MAX_N + 5];
int n;

void init(void)
{
    FORU(i, 1, n)
        parent[i] = i;
}

int find(int x)
{
    parent[x] = (parent[x] == x) ? x : find(parent[x]);
    return parent[x];
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if(rank[a] < rank[b])
        parent[a] = b;
    else
        parent[b] = a;
    if(rank[a] == rank[b])
        ++rank[a];
}

// Shorter version (without rank compression), usually faster in practice
void unite2(int a, int b)
{
    parent[find(a)] = find(b);
}
