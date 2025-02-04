class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum=0;
        int i=0;
        int max=0;

        while(i<nums.size()){
            if(i>0 && nums[i]<=nums[i-1]){
                sum=0;
            }
            sum+=nums[i];
            if(sum>max){
                max=sum;
            }
            i++;
        }
        return max;
    }
};