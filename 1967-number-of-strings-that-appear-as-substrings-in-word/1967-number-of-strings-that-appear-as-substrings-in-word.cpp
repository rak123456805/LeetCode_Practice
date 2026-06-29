class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        auto ans=0;
        for(auto &x : patterns){
            bool found=false;
            for(int i=0;i<word.size()&&!found;i++){
                string cnt="";
                for(int j=i;j<word.size();j++){
                    cnt+=word[j];
                    if(x==cnt){
                        ans++;
                        found=true;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};