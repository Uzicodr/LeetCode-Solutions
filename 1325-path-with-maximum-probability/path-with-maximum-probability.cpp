class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> ans(n, 0);
        unordered_map<int, vector<pair<int, double>>> adjacent;

        for(int i = 0; i < edges.size(); i++) {
            adjacent[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adjacent[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        ans[start_node] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while(!pq.empty()) {
            double currProb = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto &neighbor : adjacent[currNode]) {
                int adjNode = neighbor.first;
                double edgeProb = neighbor.second;

                if(currProb * edgeProb > ans[adjNode]) {
                    ans[adjNode] = currProb * edgeProb;
                    pq.push({ans[adjNode], adjNode});
                }
            }
        }

        return ans[end_node];
    }
};