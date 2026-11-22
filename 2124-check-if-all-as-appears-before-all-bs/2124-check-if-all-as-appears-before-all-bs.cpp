class Solution {
public:
    bool checkString(string s) {
        for(int i=0;i<s.size();i++){
            if(i+1<s.size() && s[i]=='b' && s[i+1]=='a')return false;
        }
        return true;
    }
};