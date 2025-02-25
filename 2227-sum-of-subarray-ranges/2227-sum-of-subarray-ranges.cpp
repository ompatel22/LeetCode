class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long total=0;
        for(int i=0;i<nums.size();i++){
            int minx=nums[i];
            int maxx=nums[i];
            for(int j=i;j<nums.size();j++){
                minx=min(minx,nums[j]);
                maxx=max(maxx,nums[j]);
                total+=(maxx-minx);
            }
        }
        return total;
    }
};