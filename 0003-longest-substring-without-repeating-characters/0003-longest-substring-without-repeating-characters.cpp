class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        for(int i=0;i<256;++i){
            hash[i]=-1;
        }
        int l=0,r=0,maxlen=0;
        while(r<s.size()){
            if(l<=r && hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            maxlen=max(maxlen,r-l+1);
            hash[s[r]]=r;
            r++;  
        }
        return maxlen;
    }
};