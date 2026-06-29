class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        auto ans=0;
        int n=patterns.size();
        for(int i=0;i<n;i++){
            string pattern=patterns[i];
            if(word.find(pattern)!=string::npos){
                ans++;
            }
        }
        return ans;
    }
};