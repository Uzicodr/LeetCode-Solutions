class Solution {
public:
    void func(vector<vector<int>>& ans,vector<int> possible,int n,int k,int cnt,int offset){
        if(cnt==k){
            ans.push_back(possible);
            return;
        }
            for(int i=offset;i<=n;i++){
            possible.push_back(i);
            func(ans,possible,n,k,cnt+1,i+1);
            possible.pop_back();
            }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> possible;

        func(ans,possible,n,k,0,1);
        return ans;
    }
};