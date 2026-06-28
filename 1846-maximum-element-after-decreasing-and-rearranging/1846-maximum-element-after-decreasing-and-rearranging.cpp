class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr[0]!=1){
            auto it=find(arr.begin(),arr.end(),1);
            if(it!=arr.end()){
                swap(arr[0],arr[it-arr.begin()]);
            }else{
               arr[0]=1;
            }
        }
            for(int i=1;i<arr.size();i++){
                if(abs(arr[i]-arr[i-1])>1){
                    arr[i] = arr[i - 1] + 1; 
                }
            }
            return *max_element(arr.begin(),arr.end());
        
    }
};