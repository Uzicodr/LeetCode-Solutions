class Solution {
public:
    void func(vector<int>& visited, vector<vector<int>>& adj,int vertex){
        visited[vertex]=1;

        for(int i=0;i<adj[vertex].size();i++){
            if(visited[adj[vertex][i]]!=1){
                func(visited,adj,adj[vertex][i]);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size());

        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(adj.size(),0);
        int ans=0;

        for(int i=0;i<visited.size();i++){
            if(visited[i]!=1){
                ans++;
                func(visited,adj,i);
            }
        }
        return ans;
    }
};