import java.util.*;

class Solution {
    public int findMaxPathScore(int[][] edges, boolean[] online, long k) {
        int n = online.length;

        List<int[]>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();

        int maxEdge = 0;
        for (int[] e : edges) {
            graph[e[0]].add(new int[]{e[1], e[2]});
            maxEdge = Math.max(maxEdge, e[2]);
        }

        int low = 0, high = maxEdge, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canReach(mid, graph, online, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    private boolean canReach(int limit, List<int[]>[] graph,
                             boolean[] online, long k) {

        int n = graph.length;

        int[] indegree = new int[n];
        for (int u = 0; u < n; u++) {
            for (int[] e : graph[u]) {
                if (e[1] >= limit &&
                    (e[0] == n - 1 || online[e[0]])) {
                    indegree[e[0]]++;
                }
            }
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.offer(i);

        long INF = Long.MAX_VALUE / 2;
        long[] dist = new long[n];
        Arrays.fill(dist, INF);
        dist[0] = 0;

        while (!q.isEmpty()) {
            int u = q.poll();

            for (int[] e : graph[u]) {
                int v = e[0], w = e[1];

                if (w < limit) continue;
                if (v != n - 1 && !online[v]) continue;

                if (dist[u] != INF) {
                    dist[v] = Math.min(dist[v], dist[u] + w);
                }

                if (--indegree[v] == 0)
                    q.offer(v);
            }
        }

        return dist[n - 1] <= k;
    }
}