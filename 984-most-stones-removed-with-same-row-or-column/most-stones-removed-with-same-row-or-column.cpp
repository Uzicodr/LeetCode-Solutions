class Solution {
public:
    vector<bool> flags;
    void dfs(vector<vector<int>>& stones,int found){
        flags[found]=true;

        for(int i=0;i<stones.size();i++){
            if(flags[i]==false &&(stones[i][0]==stones[found][0] || stones[i][1]==stones[found][1]))
            dfs(stones,i);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        flags.resize(stones.size(),false);
        int groups=0;

        for(int i=0;i<stones.size();i++){
            if(flags[i]!=true){
            groups++;
            dfs(stones,i);
            }
        }
        return stones.size()-groups;
    }
};