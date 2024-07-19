class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        set<int> minset;
        vector<int> ans;
        for(int i=0;i<matrix.size();++i)
        {
            int mi=INT_MAX;
            for(int j=0;j<matrix[i].size();++j)
            {
               mi=min(mi,matrix[i][j]);
            }
            minset.insert(mi);
        }
        for(int j=0;j<matrix[0].size();++j)
        {
            int ma=INT_MIN;
            for(int i=0;i<matrix.size();++i)
            {
               ma=max(ma,matrix[i][j]);
            }
            if(minset.find(ma)!=minset.end())
                ans.push_back(ma);
        }
        return ans;
    }
};