class Solution {
public:
    void solve(int op,int cl,int n,string curr,vector<string>&ans){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        if(op<n){
            solve(op+1,cl,n,curr+'(',ans);
        }
        if(cl<op){
            solve(op,cl+1,n,curr+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0,0,n,"",ans);
        return ans;
    }
};