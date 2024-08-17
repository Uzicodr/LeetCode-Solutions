class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        
        for(int i=0;i<nums.size()-k+1;i++)
        {
            int maximum=nums[i];
            bool flag=false;
            for(int j=0;j<k-1;j++)
            {
                if(nums[i+j]+1!=nums[j+i+1]){
                ans.push_back(-1);
                flag=true;
                break;
                }
                maximum=max(maximum,nums[j+i+1]);
            }
            if(!flag)
            ans.push_back(maximum);

            maximum=0;
        }
        return ans;
    }
};