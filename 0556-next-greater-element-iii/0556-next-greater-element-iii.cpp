class Solution {
public:
    int nextGreaterElement(int n) {
        string num=to_string(n);
        int p1=-1;
        int s=num.size();
        for(int i=s-2;i>=0;i--)
        {
            if((num[i]-'0') < (num[i+1]-'0'))
            {
                p1=i;
                break;
            }
        }
        if(p1==-1) 
            return -1;
        int min=INT_MAX;
        int p2=-1;
        for(int i=p1+1;i<s;i++)
        {
            if(num[i]>num[p1] && num[i]<min)
            {
                min=num[i];
                p2=i;
            }
        }
        if(p2==-1)
            return -1;
        swap(num[p1],num[p2]);
        sort(num.begin()+p1+1,num.end());
        long long ans=stoll(num);
        if(ans>INT_MAX)
            return -1;
        return ans;
    }
};