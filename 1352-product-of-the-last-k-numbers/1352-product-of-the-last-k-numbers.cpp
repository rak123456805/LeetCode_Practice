class ProductOfNumbers {
public:
    vector<int>ans;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        ans.push_back(num);
    }
    
    int getProduct(int k) {
        int res=1;
        int i=ans.size()-1;
        while(i>=0 && k>0){
            res*=ans[i];
            i--;
            k--;
        }
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */