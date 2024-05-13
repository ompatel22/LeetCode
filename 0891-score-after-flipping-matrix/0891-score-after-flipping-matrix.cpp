class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();++i)
        {
            if(grid[i][0]==0)
            {
                fliprow(grid,i);
            }
        }

        int power=grid[0].size()-1;
        int ans=((grid.size())*pow(2,power));
        power--;

        for(int i=1;i<grid[0].size();++i)
        {
            int c1=count1(grid,i);
            int c0=grid.size()-c1;
            ans+=(max(c1,c0))*(pow(2,power));
            power--;
        }
        return ans;
    }
    int count1(vector<vector<int>>& grid, int col)
    {
        int c=0;
        for(int i=0;i<grid.size();++i)
        {
            if(grid[i][col]==1)
                c++;
        }
        return c;
    }
    void fliprow(vector<vector<int>>& grid, int row)
    {
        for(int i=0;i<grid[0].size();++i)
        {
            grid[row][i]=(grid[row][i]==1)?0:1;
        }
    }
};