class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size(),false);
        int maxnum=0;
        for(int i:candies){
            if(i>maxnum){
                maxnum=i;
            }
        }

        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=maxnum){
                ans[i]=true;
            }
        }
        return ans;
    }
};