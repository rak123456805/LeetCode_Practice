class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        vector<int>cnt(3,-1);
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']=i;
            if(cnt[0]!=-1 && cnt[1]!=-1 && cnt[2]!=-1){
                ans+=1+min({cnt[0],cnt[1],cnt[2]});
            }
        }
        return ans;
    }
};