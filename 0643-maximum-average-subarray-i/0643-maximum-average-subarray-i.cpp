class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxavg;
        double sum=0;
        int i;
        for(i=0;i<k;++i){
            sum+=nums[i];
        }
        maxavg=(double)(sum/k);
        for(i=k;i<nums.size();++i){
            sum=sum+nums[i]-nums[i-k];
            maxavg=max(maxavg,(double)(sum/k));
        }
        return maxavg;
        }
};