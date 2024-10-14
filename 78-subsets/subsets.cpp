class Solution {
public:
    void func(vector<int>& possible,vector<vector<int>>& ans,int idx,vector<int>& nums){
        if(idx==nums.size()){
            ans.push_back(possible);
            return;
        }

        ans.push_back(possible);

        for(int i=idx;i<nums.size();i++){
            possible.push_back(nums[i]);
            func(possible,ans,i+1,nums);
            possible.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> possible;

        func(possible,ans,0,nums);
        return ans;
    }
};