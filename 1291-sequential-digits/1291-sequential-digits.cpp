class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string ans="123456789";
        vector<int>res;
        string m=to_string(low);
        int minlen=m.size();
        string h=to_string(high);
        int maxlen=h.size();
        for(int i=minlen;i<=maxlen;i++){
            for(int j=0;j+i<=9;j++){
                string subs=ans.substr(j,i);
                int ind=stoi(subs);
                if(ind>=low && ind<=high){
                    res.push_back(ind);
                }
            }
        }
        return res;
    }
};