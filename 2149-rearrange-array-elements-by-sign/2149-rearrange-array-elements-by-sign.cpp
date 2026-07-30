class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;vector<int>neg;vector<int>res(nums.size(),0);
        for(auto &it:nums){
            if(it>=0){
                pos.push_back(it);
            }else{
                neg.push_back(it);
            }
        }
        int k=0;
        int j=0;
        for(int i=0;i<res.size();i++){
            if(i%2==0){
                res[i]=pos[k];
                k++;
            }else{
                res[i]=neg[j];
                j++;
            }
        }
        return res;
    }
};