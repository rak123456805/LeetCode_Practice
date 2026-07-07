class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        if(n==0)return 0;
        string val=to_string(n);
        string x="";
        for(int i=0;i<val.size();i++){
            if(val[i]!='0'){
                x+=val[i];
                sum+=val[i]-'0';
            }
        }
        long long cnt=stoi(x);
        return sum*cnt;
    }
};