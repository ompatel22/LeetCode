class Solution {
public:
    int minBitFlips(int start, int goal) {
        int c=0;
        while(start>0 || goal>0){
            if((start&1)!=(goal&1)){
                c++;
            }
            start=start>>1;
            goal=goal>>1;
        }
        return c;
    }
};