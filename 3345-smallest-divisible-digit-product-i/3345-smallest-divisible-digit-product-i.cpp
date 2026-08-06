class Solution {
public:
    int smallestNumber(int n, int t) {
        int pro = 1;
        string val = to_string(n);
        for (int i = 0; i < val.size(); i++) {
            pro *= val[i] - '0';
        }
        while (pro % t != 0) {
            n++;
            string val = to_string(n);
            int pr = 1;
            for (int i = 0; i < val.size(); i++) {
                pr *= val[i] - '0';
            }
            pro = pr;
        }
        return n;
    }
};