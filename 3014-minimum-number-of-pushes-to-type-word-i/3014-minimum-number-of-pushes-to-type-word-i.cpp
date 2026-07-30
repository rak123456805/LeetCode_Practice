class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int>feq(26,0);
        for(auto &it:word){
            feq[it-'a']++;
        }
        int ans=0;
        sort(feq.rbegin(),feq.rend());
        for(int i=0;i<26;i++){
            if(feq[i]=='0')break;
            ans+=feq[i]*(i/8+1);
        }
        return ans;
    }
};