class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int assign=2;
        unordered_map<int,int>mp;
        int ans=0;
        for(auto &it :word){
            if(assign>9){
                assign=2;
            }
            mp[assign]++;
            ans+=mp[assign];
            assign++;
        }
        return ans;
    }
};