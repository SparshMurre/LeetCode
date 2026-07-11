class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> vis;

    int nodes, degreeSum;

    void dfs(int u) {
        vis[u] = true;
        nodes++;
        degreeSum += graph[u].size();

        for (int v : graph[u]) {
            if (!vis[v])
                dfs(v);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        graph.assign(n, {});
        vis.assign(n, false);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                nodes = 0;
                degreeSum = 0;

                dfs(i);

                if (degreeSum == nodes * (nodes - 1))
                    ans++;
            }
        }

        return ans;
    }
};