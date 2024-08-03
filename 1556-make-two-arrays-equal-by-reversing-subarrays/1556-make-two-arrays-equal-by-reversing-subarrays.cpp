class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int freq[1001]={0};
        for(int ele: target)
        {
            freq[ele]++;
        }
        for(int ele: arr)
        {
            freq[ele]--;
        }
        for(int i=1;i<1001;i++)
        {
             if(freq[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};