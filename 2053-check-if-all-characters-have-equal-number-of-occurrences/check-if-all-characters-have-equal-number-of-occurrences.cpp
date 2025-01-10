class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> freq(26,0);

        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }

        int v=-1;
        for(int i:freq){
            if(i!=0){
                v=i;
                break;
            }
        }

        if(v==-1){
            return true;
        }

        for(auto it:freq){
            if(it!=0 && it!=v){
                return false;
            }
        }
        return true;
    }
};