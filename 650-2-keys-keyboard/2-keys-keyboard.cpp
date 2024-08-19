class Solution {
public:
    int minSteps(int n) {
        if(n==1)
        return 0;

        if(n==2)
        return 2;

        int left=n;
        int curr=1;
        int ans=0;
        int clipboard=0;

        while(curr<n)
        {
            left=n-curr;
            if(left%curr!=0)
            {
                curr+=clipboard;
                ans++;
            }
            else
            {
                clipboard=curr;
                curr*=2;
                ans+=2;
            }
        }
        return ans;
    }
};