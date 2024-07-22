class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string,greater<int>> m;
        for(int i=0;i<names.size();++i)
        {
            m[heights[i]]=names[i];
        }
        int i=0;
        for(const auto& pair:m)
        {
            names[i]=pair.second;
            i++;
        }
        return names;
    }
};