class Solution {
public:
   
    bool chk(long long mid , vector<int>&piles , int h){
        long long cnt = 0;
        for(int i = 0; i < piles.size(); i++){
            cnt += (piles[i] + mid - 1) / mid;
        }

        return cnt <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
      long long lo = 1 , hi = 1e9 , ans = 0;
      while(lo <= hi){
        long long mid = (lo + hi) / 2;
        if(chk(mid , piles , h)) ans = mid , hi = mid - 1;
        else lo = mid + 1;
      }

      return ans;

    }
};