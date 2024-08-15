class Solution {
public:
    void func(vector<int>& children,vector<int>& cookies,int k,int& ans,int index)
    {
        if(index>=cookies.size())
        {
            int maxunfairness=*max_element(children.begin(),children.end());
            ans=min(maxunfairness,ans);
            return;
        }

        int curr=cookies[index];

        for(int i=0;i<children.size();i++)
        {
            children[i]+=curr;
            func(children,cookies,k,ans,index+1);
            children[i]-=curr;
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int ans=INT_MAX;
        vector<int> children(k,0);

        func(children,cookies,k,ans,0);
        return ans;
    }
};