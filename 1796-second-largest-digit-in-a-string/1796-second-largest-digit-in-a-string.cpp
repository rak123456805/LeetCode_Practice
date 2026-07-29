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
            int val=it.first-'0';
            if(val>fi){
                sec=fi;
                fi=val;
            }
        }
        return sec;
    }
};