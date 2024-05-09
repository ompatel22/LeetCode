class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> max_heap;
        for(int i=0;i<happiness.size();++i)
        {
            max_heap.push(happiness[i]);
        }
        int c=0;
        long long ans=0;
        while(k--)
        {
            ans+=(max_heap.top()-c)>0?(max_heap.top()-c):0;
            max_heap.pop();
            c++;
        }
        return ans;
    }
};