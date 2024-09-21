class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefixsum=0,maxlen=0;
        unordered_map<int,int> firstocc{{0,-1}};
        //firstocc[0]=-1;
        for(int i=0;i<nums.size();i++){
            prefixsum+=(nums[i]==1?1:-1);
            if(prefixsum==0){
                maxlen=i+1;
            }
            else if(firstocc.count(prefixsum)){
                maxlen=max(maxlen,i-firstocc[prefixsum]);
            }
            else{
                firstocc[prefixsum]=i;
            }
       }
        return maxlen;
    }
};