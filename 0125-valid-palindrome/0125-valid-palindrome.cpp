class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(auto &c : s){
            if(isalnum(c)){
                ans+=tolower(c);
            }
        }
        string res=ans;
        reverse(res.begin(),res.end());
        return res==ans;
    }
};