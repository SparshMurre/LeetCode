class Solution {
public:
    vector<int> parent;

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff)
                parent[find(i)] = find(i - 1);
        }

        vector<bool> ans;

        for (auto &q : queries)
            ans.push_back(find(q[0]) == find(q[1]));

        return ans;
    }
};