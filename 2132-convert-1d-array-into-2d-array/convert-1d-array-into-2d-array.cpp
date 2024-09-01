class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size()!=m*n)
        return {};

        vector<vector<int>> ans(m,vector<int>(n,0));

        int col=0;
        int row=0;
        for(int i=0;i<original.size();i++){
            if(col>=n){
                row++;
                col=0;
            }

            ans[row][col]=original[i];
            col++;
        }
        return ans;
    }
};