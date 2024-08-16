class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int ans=0;
        int currscore=0;
        sort(tokens.begin(),tokens.end());
        int leastpower=0;
        int mostpower=tokens.size()-1;

        while(leastpower<=mostpower)
        {
            if(power>=tokens[leastpower])
            {
                power-=tokens[leastpower];
                leastpower++;  //can use once
                currscore++;
                
                ans=currscore;
            }

            else if(currscore>0)
            {
                power+=tokens[mostpower];
                currscore--;
                mostpower--;  //can use once
            }
            else break;
        }
        return ans;
    }
};