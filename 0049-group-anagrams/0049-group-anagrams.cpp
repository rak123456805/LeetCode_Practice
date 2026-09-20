class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto word : strs){
            string w=word;
            sort(w.begin(),w.end());
            mp[w].push_back(word);
        }
        vector<vector<string>>ans;
        for(auto &m:mp){
            ans.push_back(m.second);
        }
        return ans;
    }
};