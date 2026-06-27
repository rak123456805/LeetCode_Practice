class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        for(int shift=-(m-1);shift<=n-1;shift++){
            int cnt=0;
            for(int i=0;i<n;i++){
                int j = i - shift;
                if(j<0 || j>=m)continue;
                if(nums1[i]==nums2[j]){
                    cnt++;
                    ans=max(ans,cnt);
                }else{
                    cnt=0;
                }
            }
        }
        return ans;
    }
};