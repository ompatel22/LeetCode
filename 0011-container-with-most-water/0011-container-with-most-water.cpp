class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxvol=0;
        int l=0,r=height.size()-1;
        while(l<r){
            int w=(r-l);
            int h=min(height[r],height[l]);
            maxvol=max(maxvol,(h*w));
            if(height[l]<height[r]) l++;
            else r--;
        }
        return maxvol;
    }
};