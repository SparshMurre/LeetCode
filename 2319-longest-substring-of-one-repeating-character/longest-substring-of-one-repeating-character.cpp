class Solution {
    struct Node {
        int len = 0;
        int pref = 0;
        int suff = 0;
        int best = 0;
        char left = 0;
        char right = 0;
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node c;
        c.len = a.len + b.len;
        c.left = a.left;
        c.right = b.right;

        c.pref = a.pref;
        c.suff = b.suff;
        c.best = max(a.best, b.best);

        if (a.right == b.left) {
            c.best = max(c.best, a.suff + b.pref);

            if (a.pref == a.len)
                c.pref = a.len + b.pref;

            if (b.suff == b.len)
                c.suff = b.len + a.suff;
        }

        return c;
    }

    void build(int p, int l, int r) {
        if (l == r) {
            tree[p] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = (l + r) / 2;

        build(p * 2, l, mid);
        build(p * 2 + 1, mid + 1, r);

        tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, char c) {
        if (l == r) {
            tree[p] = {1, 1, 1, 1, c, c};
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(p * 2, l, mid, idx, c);
        else
            update(p * 2 + 1, mid + 1, r, idx, c);

        tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();
        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};