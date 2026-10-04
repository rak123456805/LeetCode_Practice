class Solution {
public:
    long long M=1e9+7;
        pair<long long,long long>fib(long n){
            if(n==0)return {0,1};
            auto p=fib(n/2);
            long long a=p.first;
            long long b=p.second;
            long long c=(a*((2*b%M-a+M)%M))%M;
            long long d=(a*a%M+b*b%M)%M;
            if(n%2==0)return {c,d};
            return {d,(c+d)%M};
        }
    int countGoodStrings(long long n) {
        long long f=fib(n).first;
        return (2*f)%M;
    }
};