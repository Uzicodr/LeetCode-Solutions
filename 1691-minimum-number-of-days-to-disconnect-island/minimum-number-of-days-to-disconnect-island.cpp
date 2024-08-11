class Solution {
public:
    void DFS(vector<vector<int>>& matrix,vector<vector<bool>>& flags,int i,int j)
    {
        if(i<0||j<0||i>=matrix.size()||j>=matrix[0].size()||matrix[i][j]==0||flags[i][j]==true)
        return;

        flags[i][j]=true;

        DFS(matrix,flags,i+1,j);
        DFS(matrix,flags,i-1,j);
        DFS(matrix,flags,i,j+1);
        DFS(matrix,flags,i,j-1);

    }
    int count(vector<vector<int>>& matrix)
    {
        vector<vector<bool>> flags(matrix.size(),vector<bool>(matrix[0].size(),false));
        int cnt=0;

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==1 && flags[i][j]==false)
                {
                    cnt++;
                    DFS(matrix,flags,i,j);
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        int n=count(grid);

        if(n!=1)
        return 0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=0;

                    if(count(grid)!=1)
                    return 1;

                    grid[i][j]=1;
                }
            }
        }
        return 2; //maximal 4 blocks of island so just cut diagonally a 4x4, so 2
    }
};