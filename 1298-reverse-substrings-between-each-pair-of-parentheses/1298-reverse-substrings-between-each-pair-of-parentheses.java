class Solution {
    public String reverseParentheses(String s) {
        Stack<Integer> st=new Stack<>();
        StringBuilder res=new StringBuilder();
        int [] arr=new int[s.length()];
        for(int i=0;i<s.length();i++)
        {
            char c=s.charAt(i);
            if(c=='(')
            {
                st.push(i);
            }
            else if(c==')')
            {
                int openind=st.pop();
                arr[i]=openind;
                arr[openind]=i;
            }
        }
        int dir=1;
        int i=0;
        while(i<s.length())
        {
            if(s.charAt(i)=='(' || s.charAt(i)==')')
            {
                dir*=-1;
                i=arr[i];
            }
            if(s.charAt(i)!='(' && s.charAt(i)!=')')
            {
                res.append(s.charAt(i));
                
            }
            i+=dir;
        }
        return res.toString();
        
    }
}