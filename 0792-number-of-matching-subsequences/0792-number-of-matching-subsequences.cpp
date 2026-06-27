class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
      int res=0;
      int n=s.size();
      int m=words.size();
      unordered_map<char,vector<int>>mp;
      for(int i=0;i<n;i++){
        mp[s[i]].push_back(i);
      }
      for(auto &word:words){
        int priv=-1;
        bool ok=true;
        for(auto &ch :word){
            auto &v =mp[ch];
            auto it = upper_bound(v.begin(), v.end(), priv);
            if(it==v.end()){
                ok=false;
                break;
            }
            priv=*it;
        }
        if(ok)res++;
      }
      return res;
    }
};