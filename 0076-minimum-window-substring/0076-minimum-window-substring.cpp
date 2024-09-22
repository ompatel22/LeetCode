class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256];
        for(int i=0;i<256;i++){
            hash[i]=0;
        }
        for(int i=0;i<t.size();++i){
            hash[t[i]]++;
        }
        int l=0,r=0,minlen=INT_MAX,startind=-1,cnt=0;
        while(r<s.size()){
            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;
            while(cnt==t.size()){
                if(minlen>(r-l+1)){
                    minlen=(r-l+1);
                    startind=l;
                }
                if(l<=r){
                    hash[s[l]]++;
                    if(hash[s[l]]>0){
                    cnt--;
                    }
                    l++;
                } 
            }
            r++;
        }
        string str=(minlen==INT_MAX)?"":s.substr(startind,minlen);
        return str;
    }
};