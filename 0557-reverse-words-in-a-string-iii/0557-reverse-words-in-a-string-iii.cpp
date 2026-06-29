class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int x=0;
        for (int i = 0; i < n; i++) {
           if(s[i]==' '){
              reverse(s.begin()+x,s.begin()+i);
              x=i+1;
              i=x;
           }
           if(i==n-1){
            reverse(s.begin()+x,s.end());
           }
        }
        return s;
    }
};