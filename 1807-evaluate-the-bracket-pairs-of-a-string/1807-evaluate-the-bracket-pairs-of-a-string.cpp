class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& word : knowledge) {
            mp[word[0]] = word[1];
        }
        string val = "";
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if(s[i]=='('){
                i++;
                string ans="";
                while(s[i]!=')'){
                    ans+=s[i];
                    i++;
                }
                if(mp.find(ans)!=mp.end()){
                    val+=mp[ans];
                }else{
                    val+='?';
                }
            }else{
                val+=s[i];
            }
        }
        return val;
    }
};