class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int maxelement=*max_element(nums.begin(),nums.end());
        
        vector<int> possible(maxelement+1,0);

        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                possible[abs(nums[j]-nums[i])]++;
            }
        }

        for(int i=0;i<possible.size();i++)
        {
            k-=possible[i];
            if(k<=0)
            return i;
        }

        return 0;
    }
};