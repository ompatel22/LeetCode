class Solution {
public:
    int sod(int n)
    {
        int s=0;
        for(n;n>0;n=(n/10))
        {
            s+=((n%10)*(n%10));
        }
        return s;
    }
    bool isHappy(int n) {
      int slow=n,fast=n;
      do
      {
        slow=sod(slow);
        fast=sod(sod(fast));
        if(fast==1)return true;
      }while(slow!=fast);
      return false;
    }
};