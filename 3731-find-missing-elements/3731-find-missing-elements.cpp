class Solution {
public:
int n;
   bool find(vector<int>& nums,int i){
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(i==nums[mid]){
            return true;
        }
        else if(i>nums[mid]){
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    return false;
   }
    vector<int> findMissingElements(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        int start=nums[0];
        int end=nums[n-1];
        vector<int>ans;
        for(int i=start;i<end;i++){
            if(!find(nums,i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};