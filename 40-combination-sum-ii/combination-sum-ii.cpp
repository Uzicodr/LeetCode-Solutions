class Solution {
public:
    void func(vector<int>& candidates, int target,vector<int> temp,vector<vector<int>>& ans,int index)
    {
        if(target<0||index>candidates.size())
        return;
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<candidates.size();i++)
        {
            if(i>index&&candidates[i]==candidates[i-1])
            continue;

            temp.push_back(candidates[i]);
            func(candidates,target-candidates[i],temp,ans,i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(),candidates.end());
        func(candidates,target,temp,ans,0);

        return ans;

    }
};