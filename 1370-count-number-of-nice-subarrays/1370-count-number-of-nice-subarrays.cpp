class Solution {
public:

    int getCount(vector<int>& nums, int k){
        int l=0,r=0,odd_c=0;
        long long cnt=0;
        int n=nums.size();
        while(r<n){
            if(nums[r]%2==1){
                odd_c++;
            }
            while(odd_c > k && l<n){
                if(nums[l]%2==1){
                    odd_c--;
                }
                l++;
            }
            r++;
            cnt+=(r-l+1);
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int c1=getCount(nums,k);
        int c2=getCount(nums,k-1);
        return c1-c2;
    }
};