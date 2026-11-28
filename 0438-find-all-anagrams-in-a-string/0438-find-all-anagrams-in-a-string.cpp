class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        vector<int> a(26,0), b(26,0);
        int k=p.size();
        if(k>n) return {};
        for(int i=0;i<k;i++){
            a[p[i]-'a']++;
            b[s[i]-'a']++;
        }
        vector<int>ans;
        if(a==b)ans.push_back(0);
        for(int i=k;i<n;i++){
            b[s[i-k]-'a']--;
            b[s[i]-'a']++;
            if(a==b)ans.push_back(i-k+1);
        }
        return ans;
    }
};