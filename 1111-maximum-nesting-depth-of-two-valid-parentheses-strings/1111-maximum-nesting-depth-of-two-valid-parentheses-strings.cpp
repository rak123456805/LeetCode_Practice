class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int>ans;
        int d=0;
        for(auto &s : seq){
            if(s=='('){
                d++;
                ans.push_back(d%2);
                
            }else{
                ans.push_back(d%2);
                d--;
            }
        }
        return ans;
    }
};