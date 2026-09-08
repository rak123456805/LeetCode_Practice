class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ri=0;
        int le=n-1;
        int ans=0;
        for(int i=0;i<n;i++){
            while(ri<le){
                int hi=min(height[ri],height[le]);
                int wi=abs(ri-le);
                ans=max(ans,(hi*wi));
                if(height[ri]<height[le])ri++;
                else le--;
            }
        }
        return ans;
    }
};