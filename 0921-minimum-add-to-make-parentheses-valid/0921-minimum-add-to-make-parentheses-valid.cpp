class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int op=0;
        for(auto &c  : s){
            if(c=='('){
                op++;
            }else{
                if(op>0){
                    op--;
                }else{
                    ans++;
                }
            }
        }
        return op+ans;
    }
};