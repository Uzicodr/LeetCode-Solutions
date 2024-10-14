class Solution {
public:
    void func(vector<vector<int>>& ans,int target,vector<int>& candidates,vector<int>& possible,int idx){
        if(target==0){
            ans.push_back(possible);
            return;
        }

        if(idx>=candidates.size())
        return;

        if(target<0)
        return;

        if(target>=candidates[idx]){
            possible.push_back(candidates[idx]);
            func(ans,target-candidates[idx],candidates,possible,idx);
            possible.pop_back();
        }
        
        func(ans,target,candidates,possible,idx+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> possible;

        func(ans,target,candidates,possible,0);
        return ans;
    }
};