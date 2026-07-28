class Solution {
public:
    int secondHighest(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                mp[s[i]]++;
            }
        }
        int fi=-1;
        int sec=-1;
        for(auto &it : mp){
            int l=it.first-'0';
            if(l>fi){
                sec=fi;
                fi=l;
            }
        }
        return sec;
    }
};