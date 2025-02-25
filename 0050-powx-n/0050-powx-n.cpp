class Solution {
public:
    double myPow(double x, int n) {
        if(x==1) return 1;
        if(n==0) return 1;
        // if(n==INT_MIN){
        //     n=INT_MAX;
        //     x=1/x;
        // }
        double ans=1;
        long long nn=n;
        if(n<0){
            nn*=-1;
            x=1/x;
        }

        while(nn>0){
            if(nn%2==0){
                x*=x;
                nn=nn/2;
            }else{
                ans*=x;
                nn=nn-1;
            }
        }
        return ans;
    }
};