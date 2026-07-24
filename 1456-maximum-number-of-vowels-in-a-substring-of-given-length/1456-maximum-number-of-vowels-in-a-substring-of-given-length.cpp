class Solution {
public:
    bool isvowel(char val){
        if(val=='a'||val=='e'||val=='i'||val=='o'||val=='u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int maxvowel=0,le=0,vowel=0;
        for(int ri=0;ri<n;ri++){
            if(isvowel(s[ri]))vowel++;
            if((ri-le+1)==k){
                maxvowel=max(maxvowel,vowel);
                if(isvowel(s[le]))vowel--;
                le++;
            }
        }
        return maxvowel;
    }
};