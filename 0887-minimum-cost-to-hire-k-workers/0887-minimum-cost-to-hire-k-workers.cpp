class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> workers(quality.size());
        for(int i=0;i<quality.size();++i)
        {
            workers[i]={(wage[i]*1.0/quality[i]),quality[i]};
        }
        sort(workers.begin(),workers.end());
        double ans=DBL_MAX;
        int qualitysum=0;
        priority_queue<int> q;
        for(auto worker: workers)
        {
            double currRatio=worker.first;
            qualitysum+=worker.second;
            q.push(worker.second);
            if(q.size()>k)
            {
                qualitysum-=q.top();
                q.pop();
            }
            if(q.size()==k)
            {
                ans=min(ans,qualitysum*currRatio);
            }
        }
        return ans;
    }
};