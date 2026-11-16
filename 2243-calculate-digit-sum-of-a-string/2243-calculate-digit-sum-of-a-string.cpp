class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string ans = "";
            int val = 0;
            int j = 0;
            for (int i = 0; i < s.size(); i++) {
                val += s[i] - '0';
                j++;
                if (j == k) {
                    ans += to_string(val);
                    cout<<ans<<" ";
                    val = 0;
                    j = 0;
                }
               
            }
           if(j>0){
             ans += to_string(val);
           }
            
            s = ans;
        }
        return s;
    }
};