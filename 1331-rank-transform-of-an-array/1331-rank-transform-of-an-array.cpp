class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       unordered_map<int,int>mp;
       vector<int>s=arr;
       int rank=1;
       sort(s.begin(),s.end());
       for(auto &x : s){
          if(mp.find(x)==mp.end()){
                mp[x]=rank++;
          }
       }
       vector<int>ans;
       for(auto &a : arr){
           ans.push_back(mp[a]);
       }
       return ans;
    }
};