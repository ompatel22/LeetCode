class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int s=nums.size();
        vector<int> right(s);
        vector<int> left(s);
        vector<int> ans(s);
        left[0]=1;
        right[s-1]=1;
        for(int i=1;i<s;i++)
        {
            left[i]=left[i-1]*nums[i-1];
        }
        for(int i=s-2;i>=0;i--)
        {
            right[i]=right[i+1]*nums[i+1];
        }
        for(int i=0;i<s;i++)
        {
            ans[i]=left[i]*right[i];
        }
        return ans;
    }
};