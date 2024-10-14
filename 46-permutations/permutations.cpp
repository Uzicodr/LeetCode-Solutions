class Solution {
public:
    void func(vector<int>& nums,vector<bool>& freq,vector<int>& possible,vector<vector<int>>& ans){
        if(possible.size()==nums.size()){
            ans.push_back(possible);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(freq[i]==0){
                freq[i]=1;
                possible.push_back(nums[i]);
                func(nums,freq,possible,ans);
                freq[i]=0;
                possible.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> freq(nums.size(),0);
        vector<vector<int>> ans;
        vector<int> possible;

        func(nums,freq,possible,ans);
        return ans;
    }
};