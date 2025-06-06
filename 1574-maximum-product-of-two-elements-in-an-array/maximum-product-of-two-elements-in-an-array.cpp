class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        int a=pq.top()-1;
        pq.pop();
        int b=pq.top()-1;

        return a*b;
    }
};