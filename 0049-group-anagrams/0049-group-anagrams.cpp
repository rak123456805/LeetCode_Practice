class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto &s:strs){
            auto w=s;
            sort(w.begin(),w.end());
            mp[w].push_back(s);
        }
        for(auto &s:mp){
            ans.push_back(s.second);
        }
        return ans;
    }
};