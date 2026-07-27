class Solution {
public:
    int solve(int n){
        if(n<=1)return n;
        int las=solve(n-1);
        int sec=solve(n-2);
        return las+sec;
    }
    int fib(int n) {
        return solve(n);
    }
};