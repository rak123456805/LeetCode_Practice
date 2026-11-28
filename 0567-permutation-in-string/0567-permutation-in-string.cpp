class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size();
        int n=s2.size();
        if(k>n)return false;
        vector<int>a(26,0), b(26,0);
        for(int i=0;i<k;i++){
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }
        if(a==b)return true;
        for(int i=k;i<n;i++){
            b[s2[i-k]-'a']--;
            b[s2[i]-'a']++;
            if(a==b)return true;
        }
        return false;
    }
};