class Solution {

    int[] parent;

    public int minScore(int n, int[][] roads) {
        parent = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Build connected components
        for (int[] road : roads) {
            union(road[0], road[1]);
        }

        int root = find(1);
        int ans = Integer.MAX_VALUE;

        // Find the minimum edge in the component containing city 1
        for (int[] road : roads) {
            if (find(road[0]) == root) {
                ans = Math.min(ans, road[2]);
            }
        }

        return ans;
    }

    private int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    private void union(int a, int b) {
        parent[find(a)] = find(b);
    }
}