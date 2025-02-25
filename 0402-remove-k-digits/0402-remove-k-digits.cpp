class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k) {
            return "0";
        }

        stack<char> st;
        const int n = num.size();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && k && num[i] < st.top()) {
                st.pop();
                k--;
            }
            if (!(num[i] == '0' && st.empty())) {
                st.push(num[i]);
            }
        }
        while(!st.empty() && k){
            st.pop();
            k--;
        }

        if (st.empty()) {
            return "0";
        }

        string s(st.size(), ' ');
        int i = st.size() - 1;
        while (!st.empty()) {
            s[i] = st.top();
            st.pop();
            i--;
        }

        return s;
    }
};