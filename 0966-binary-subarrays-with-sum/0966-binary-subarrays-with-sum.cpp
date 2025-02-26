class Solution {
public:
    int get_count(vector<int>& nums, int goal){

        if(goal < 0)
            return 0;

        int l=0,r=0,cnt=0;
        long long sum=0;
        while(r < nums.size()){
            sum += nums[r];

            while(sum > goal && l < nums.size()){
                sum -= nums[l];
                l++;
            }

            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int c1=get_count(nums,goal);
        int c2=get_count(nums,goal-1);
        return c1-c2;
    }
};