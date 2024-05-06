class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp(nums2.size());
        stack<int> s;
        int n=nums2.size();
        for(int i=n-1;i>=0;--i)
        {
            while(!s.empty() && s.top()<=nums2[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                mp[nums2[i]]=s.top();
            }
            else
            {
                mp[nums2[i]]=-1;
            }
            s.push(nums2[i]);
        }
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();++i)
        {
            ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};