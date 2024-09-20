class Solution {
    public String largestNumber(int[] nums) {
        int f=1;
        String [] n=new String[nums.length];
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=0){f=-1;}
            n[i]=String.valueOf(nums[i]);
        }
        if(f==1){return "0";}
        Arrays.sort(n,(a,b)->(b+a).compareTo(a+b));
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<nums.length;i++){
            sb.append(n[i]);
        }
        return sb.toString();
    }
}