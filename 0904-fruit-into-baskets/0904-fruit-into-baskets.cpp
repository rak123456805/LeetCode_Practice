class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int le=0;
        int ans=0;
        unordered_map<int,int>mp;
        for(int ri=0;ri<n;ri++){
            mp[fruits[ri]]++;
            while(mp.size()>2){
                mp[fruits[le]]--;
                if(mp[fruits[le]]==0){
                    mp.erase(fruits[le]);
                }
                le++;
            }
            ans=max(ans,ri-le+1);
        }
        return ans;
    }
};