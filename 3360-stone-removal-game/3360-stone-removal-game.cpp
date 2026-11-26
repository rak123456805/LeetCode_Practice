class Solution {
public:
    bool canAliceWin(int n) {
        int t=10,k=0;
        while(n>=t){
            n-=t;
            t--;
            k++;
        }
        if(k%2==1)return true;
        return false;
    }
};