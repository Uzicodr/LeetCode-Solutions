class Solution {
public:
    void func(vector<string>& ans,string mapping[],string digits,int idx,string possibleans){
        if(idx==digits.length()){
            ans.push_back(possibleans);
            return;
        }

        string button=mapping[digits[idx]-'2'];

        for(int i=0;i<button.length();i++){
            possibleans+=button[i];
            func(ans,mapping,digits,idx+1,possibleans);
            possibleans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        string mapping[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;

        int idx=0;
        func(ans,mapping,digits,idx,"");
        return ans;
    }
};