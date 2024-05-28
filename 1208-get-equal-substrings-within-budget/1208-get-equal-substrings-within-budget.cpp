class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> arr(s.size());
        for(int i=0;i<s.size();++i)
        {
            arr[i]=abs(s[i]-t[i]);
        }
        int l=0,r=0,temp=0,ans=0;
        while(r < s.size())
        {
            temp+=arr[r];
            while(temp > maxCost)
            {   
                temp-=arr[l];
                l++;
            }
            ans=max(ans,(r-l+1));
            r++;
        }
        return ans;
    }
};  