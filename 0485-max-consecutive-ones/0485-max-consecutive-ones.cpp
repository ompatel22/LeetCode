class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0,r=0;
        int maxlen=0;
        int sum=nums[0];
        while(r<nums.size()){
            while(l<=r && sum!=(r-l+1)){
                sum-=nums[l];
                l++;
            }
            if(sum==(r-l+1)){
                maxlen=max(maxlen,r-l+1);            
            }
            r++;
            if(r<nums.size())
                sum+=nums[r];
        }
        return maxlen;
    }
};