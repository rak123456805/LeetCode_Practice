class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0;
        vector<int>vec;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                vec.push_back(ans);
                ans=0;
            }else{
                if(s[i-1]=='('){
                    ans=vec.back()+1;
                }else{
                    ans=vec.back()+(2*ans);
                }
                vec.pop_back();
            }
        }
        return ans;
    }
};