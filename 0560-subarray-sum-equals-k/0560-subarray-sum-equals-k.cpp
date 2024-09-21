class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int prefixsum=0, ans=0;
        mp[0]=1;
        for(int i=0;i<nums.size();++i){
            prefixsum+=nums[i];
            int remove=prefixsum-k;
            ans+=mp[remove];
            mp[prefixsum]+=1;
        }
        return ans;
    }
};