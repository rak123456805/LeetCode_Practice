class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            int val = 0;
            string cnt = "";
            for (int j = i; j < s.size(); j++) {
                cnt+=s[j];
                if(s[j]=='1')val++;
                if(val==k){
                    if(ans==""||cnt.size()<ans.size()||(cnt.size()==ans.size()&&cnt<ans)){
                        ans=cnt;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};