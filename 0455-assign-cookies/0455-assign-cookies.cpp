class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0,j=0;
        int n=g.size();
        int k=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<k && j<n){
            if(s[i]>=g[j]){
                j++;
            }
            i++;
        }
        return j;
    }
};