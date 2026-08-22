class Solution {
public:
    int sum(int n){
        string ans=to_string(n);
        int val=0;
        for(int i=0;i<ans.size();i++){
            val+=ans[i]-'0';
        }
        return val;
    }
    int prod(int n){
        string ans=to_string(n);
        int val=1;
        for(int i=0;i<ans.size();i++){
            val*=ans[i]-'0';
        }
        return val;
    }
    bool checkDivisibility(int n) {
       int val=sum(n)+prod(n); 
        return (n%val==0);
    }
};