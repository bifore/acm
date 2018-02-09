// https://github.com/radoslav11/Coding-Library/blob/master/data_structures/segment_tree.cpp

const int MAX_N = ???

int n;
int a[MAX_N];

struct node
{
    int sum;
    node() { sum = 0; }
    node(int v) { sum = v; }
};

node tmp, neutral;

node merge(node a, node b)
{
    tmp.sum = a.sum + b.sum;
    return tmp;
}

struct segment_tree
{
    node tree[4 * MAX_N];

    void init(int idx, int left, int right)
    {
        if(left == right)
        {
            tree[idx] = node(a[left]);
            return;
        }

        int mid = (left + right) / 2;
        init(2 * idx, left, mid);
        init(2 * idx + 1, mid + 1, right);
        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    void update(int idx, int left, int right, int pos, int val)
    {
        if(left > pos || right < pos)
            return;
        if(left == right && left == pos)
        {
            tree[idx].sum += val;
            return;
        }

        int mid = (left + right) / 2;
        update(2 * idx, left, mid, pos, val);
        update(2 * idx + 1, mid + 1, right, pos, val);
        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    node query(int idx, int left, int right, int q_left, int q_right)
    {
        if(left > q_right || right < q_left)
            return neutral;
        if(q_left <= left && right <= q_right)
            return tree[idx];

        int mid = (left + right) / 2;
        return merge(   query(2 * idx, left, mid, q_left, q_right),
                        query(2 * idx + 1, mid + 1, right, q_left, q_right)); 
    }
};
