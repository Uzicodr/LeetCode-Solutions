class Solution {
public:
    const int LARGE_VALUE = 2e9;

    long long DijkstraAlgo(vector<vector<int>>& edges, int n, int src, int dest) {
        unordered_map<long long, vector<pair<long long, long long>>> adj;

        for(vector<int>& edge : edges) {
            if(edge[2] != -1) {
                int u  = edge[0];
                int v  = edge[1];
                int wt = edge[2];

                adj[u].push_back({v, wt});
                adj[v].push_back({u, wt});
            }
        }

        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
        vector<long long> result(n, INT_MAX);

        result[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            long long currDist = pq.top().first;
            long long currNode = pq.top().second;
            pq.pop();

            for(auto&[nbr, wt] : adj[currNode]) {
                if(result[nbr] > currDist + wt) {
                    result[nbr] = currDist + wt;
                    pq.push({result[nbr], nbr});
                }
            }
        }

        return result[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        long long currShortestDist = DijkstraAlgo(edges, n, source, destination);

        if(currShortestDist < target) {
            return {};
        }

        bool matchedTarget = (currShortestDist == target);

        for(vector<int>& edge : edges) {
            if(edge[2] == -1) {

                edge[2] = (matchedTarget == true) ? LARGE_VALUE : 1; 

                if(matchedTarget != true) {
                    long long newShortestDist = DijkstraAlgo(edges, n, source, destination);

                    if(newShortestDist <= target) {
                        matchedTarget = true;
                        edge[2] += (target - newShortestDist);
                    }
                }
            }
        }

        if(matchedTarget == false) {
            return {};
        }
        return edges;
    }
};