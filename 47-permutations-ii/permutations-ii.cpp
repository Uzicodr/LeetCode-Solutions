class Solution {
public:
    void func(vector<vector<int>>& ans,vector<int>& nums,int idx){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=idx;i<nums.size();i++){
            bool flag=true;

            for (int j = idx; j < i; j++) {
                if (nums[j] == nums[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag){
            swap(nums[i],nums[idx]);
            func(ans,nums,idx+1);
            swap(nums[i],nums[idx]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        func(ans,nums,0);
        return ans;
    }
};