class Solution {
public:
    bool func(int idx,vector<vector<char>>& board,vector<vector<int>>& visited,int m,int n,int i,int j,string word){
        if(idx==word.length()){
            return true;
        }

        if(i>=0 && j>=0 && i<m && j<n && visited[i][j]==0 && board[i][j]==word[idx]){
        visited[i][j]=1;

        if(func(idx+1,board,visited,m,n,i+1,j,word)||func(idx+1,board,visited,m,n,i-1,j,word)||func(idx+1,board,visited,m,n,i,j+1,word)||func(idx+1,board,visited,m,n,i,j-1,word))
        return true;
        
        visited[i][j]=0;
    }
    return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && func(0,board,visited,m,n,i,j,word)){
                    return true;
                }
            }
        }
        return false;
    }
};