class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        int n=arr2.size();
        for(int i=0;i<arr1.size();i++){
            int res=0;
            for(int j=0;j<arr2.size();j++){
                if(abs(arr1[i]-arr2[j])<=d)continue;
                else res++;
            }
            if(res==n)ans++;
        }
        return ans;
    }
};