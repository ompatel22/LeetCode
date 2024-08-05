class Solution {
public:
    int countSeniors(vector<string>& details) {
        int c=0;
        for(string s: details){
            if(s[11]>(6+'0')){
                c++;
            }
            else if(s[11]==(6+'0') && s[12]>=(1+'0')){
                c++;
            }
        }
        return c;
    }
};