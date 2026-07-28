class Solution {
public:
    int secondHighest(string s) {
        int fi=-1;
        int se=-1;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                int k=s[i]-'0';
                if(k>fi){
                    se=fi;
                    fi=k;
                }
                else if (k < fi && k > se) {
                    se = k;
                }
            }
        }
        return se;
    }
};