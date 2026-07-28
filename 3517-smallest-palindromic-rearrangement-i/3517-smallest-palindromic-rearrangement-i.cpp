class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()==1||s.size()==0)return  s;
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        string left="";
        string mid="";
        for(auto &it :mp){
            if(it.second%2!=0){
                mid+=it.first;
            }
            int n=it.second/2;
            left+=string(n,it.first);
        }
        string right=left;
        reverse(right.begin(),right.end());
        if(mid!=""){
            return left+mid+right;
        }
        return left+right;
    }
};