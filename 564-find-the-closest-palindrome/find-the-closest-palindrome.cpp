class Solution {
public:
    long func(long half,bool flag)
    {
        long mirrored=half;
        if(!flag)
        half/=10;

        while(half>0)
        {
            int num=half%10;
            mirrored=(mirrored*10)+num;
            half/=10;
        }
        return mirrored;
    }
    string nearestPalindromic(string n) {
        long half;
        if(n.length()%2==0)
        half=stol(n.substr(0,n.length()/2));
        else
        half=stol(n.substr(0,(n.length()/2)+1));

        vector<long> palindromes;
        palindromes.push_back(func(half,n.length()%2==0));
        palindromes.push_back(func(half+1,n.length()%2==0));
        palindromes.push_back(func(half-1,n.length()%2==0));
        palindromes.push_back((long)pow(10,n.length()-1)-1);
        palindromes.push_back((long)pow(10,n.length())+1);

        long input=stol(n);
        long ans=LONG_MAX;
        long diff=LONG_MAX;
        for(int i=0;i<palindromes.size();i++)
        {
            if(palindromes[i]==input)
            continue;

            if(abs(palindromes[i]-input)<diff){
            diff=abs(palindromes[i]-input);
            ans=palindromes[i];
            }
            else if(abs(palindromes[i]-input)==diff)
            ans=min(ans,palindromes[i]);
        }
        return to_string(ans);
    }
};