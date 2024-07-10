class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(string s: logs)
        {
            if(s!="./" && s!="../")
                ans++;
            if(s=="../")
                if(ans>0){ans--;}
        }
        return ans;
    }
};