class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        stack<char>st;
        for(auto &c :s){
            if(c=='('){
                st.push('(');
            }else{
                if(!st.empty()&&st.top()=='('){
                    st.pop();
                }else{
                    cnt++;
                }
            }
        }
        if(!st.empty()){
            cnt+=st.size();
        }
        return cnt;
    }
};