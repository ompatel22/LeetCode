class Solution {
public:
    int numberOfSubstrings(string arr) {
        int freq[3] = {0};  // To count frequency of 'a', 'b', and 'c'
        int l = 0, r = 0, total = 0, n = arr.size();

        while (r < n) {
            // Expand the window by moving the right pointer
            freq[arr[r] - 'a']++;

            // Check if the current window contains all 'a', 'b', and 'c'
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // Count all substrings that start from any index between 'l' and 'r'
                total += (n - r);

                // Shrink the window by moving the left pointer
                freq[arr[l] - 'a']--;
                l++;
            }

            // Move the right pointer forward
            r++;
        }

        return total;
    }
};
