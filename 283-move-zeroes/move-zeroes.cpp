class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size() - k; ) {
            if (nums[i] == 0) {
                for (int j = i; j < nums.size() - k - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                nums[nums.size() - k - 1] = 0;
                k++;
            } else {
                i++;
            }
        }
    }
};
