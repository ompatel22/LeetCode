
class Solution {
public:
    void do_empty(stack<int> &st){
        while(!st.empty()){
            st.pop();
        }
    }

    long long subArrayRanges(vector<int>& arr) {

        // o(n^2)
        //  long long total=0;
        //  for(int i=0;i<nums.size();i++){
        //      int minx=nums[i];
        //      int maxx=nums[i];
        //      for(int j=i;j<nums.size();j++){
        //          minx=min(minx,nums[j]);
        //          maxx=max(maxx,nums[j]);
        //          total+=(maxx-minx);
        //      }
        //  }
        //  return total;

        // now in o(n)

        int n = arr.size();
        stack<int> st;
        vector<int> pse(n, -1), pge(n, -1), nse(n, -1), nge(n, -1);

        // Previous Smaller Element (PSE)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }

        do_empty(st);

        // Next Smaller Element (NSE)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }

        do_empty(st);

        // Previous Greater Element (PGE)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] >= arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                pge[i] = st.top();
            }
            st.push(i);
        }

        do_empty(st);

        // Next Greater Element (NGE)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(i);
        }

        long long total1 = 0, total2 = 0;
        for (int i = 0; i < n; i++) {
            // Min contribution
            int leftc1 = (pse[i] == -1) ? i + 1 : i - pse[i];
            int rightc1 = (nse[i] == -1) ? n - i : nse[i] - i;
            total1 += (long long)leftc1 * rightc1 * arr[i];

            // Max contribution
            int leftc2 = (pge[i] == -1) ? i + 1 : i - pge[i];
            int rightc2 = (nge[i] == -1) ? n - i : nge[i] - i;
            total2 += (long long)leftc2 * rightc2 * arr[i];
        }

        return total2 - total1;
    }
};