class Solution {
public:
    int numberOfSubstrings(string arr) {
        int freq[3] = {0};
        int l = 0, r = 0, total = 0, n = arr.size();
        while (r <= n) {
            if (freq[0] && freq[1] && freq[2]) {
                total += 1 + (n - r);
                freq[arr[l] - 'a']--;
                l++;
            } else if (r<n) {
                freq[arr[r] - 'a']++;
                r++;
            } else {
                r++;
            }
            if (r == n && r - l == 2) {
                break;
            }
        }
        return total;
    }
};