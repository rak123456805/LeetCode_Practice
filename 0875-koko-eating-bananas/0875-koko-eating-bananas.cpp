class Solution {
public:
    bool solve(long long mid,vector<int>&piles,int k){
        long long cnt=0;
        for(auto &x :piles){
            cnt+=(x/mid);
            if(x%mid!=0){
                cnt++;
            }
        }
        return cnt<=k;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
        int
         hi=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(lo<=hi){
            long long mid=(lo+hi)/2;
            if(solve(mid,piles,h)){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return lo;
    }
};