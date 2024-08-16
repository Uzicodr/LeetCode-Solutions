class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int pastmin=arrays[0][0];
        int pastmax=arrays[0].back();
        int ans=0;

        for(int i=1;i<arrays.size();i++)
        {
            int currmin=arrays[i][0];
            int currmax=arrays[i].back();
            ans=max({ans,abs(pastmax-currmin),abs(pastmin-currmax)});

            pastmin=min(pastmin,arrays[i][0]);
            pastmax=max(pastmax,arrays[i].back());
        }

        return ans;
    }
};