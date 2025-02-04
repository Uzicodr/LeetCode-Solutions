class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int smallest=1;
        int largest=1;
        int smax=1;
        int lmax=1;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                largest++;
            }
            else{
                if(largest>lmax){
                    lmax=largest;  
                }
                largest=1;
            }
            if(nums[i]>nums[i+1]){
                smallest++;
            }
            else{
                if(smallest>smax){
                    smax=smallest;
                }
                smallest=1;
            }
        }

        if(smallest>smax){
            smax=smallest;
        }
        if(largest>lmax){
            lmax=largest;
        }

        if(lmax>smax){
            return lmax;
        }
        return smax;
    }
};