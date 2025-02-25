class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, max_freq = 0, max_len = 0, f = 1;
        int freq[26] = {0};
        int n = s.size();
        while (r < n) {
            if (f == 1) {
                freq[s[r] - 'A']++;
                max_freq = max(max_freq, freq[s[r] - 'A']);
            }
            if ((r - l + 1) - max_freq <= k) {
                max_len = max(max_len, r - l + 1);
                r++;
                f = 1;
            } else {
                while ((r - l + 1) - max_freq > k) {
                    freq[s[l] - 'A']--;
                    l++;
                    f = 0;
                    max_freq = 0;
                    for (int i = 0; i < 26; i++) {
                        max_freq = max(max_freq, freq[i]);
                    }
                }
            }
        }
        return max_len;
    }
};