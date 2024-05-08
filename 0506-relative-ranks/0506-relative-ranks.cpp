class Solution {
public:
        vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());
        int maxScore = *max_element(score.begin(), score.end());
        vector<int> indarr(maxScore + 1, -1);

        for (int i = 0; i < score.size(); ++i) {
            indarr[score[i]] = i + 1;
        }

        int rank = 1;
        for (int i = maxScore; i >= 0; --i) {
            if (indarr[i] != -1) {
                if (rank == 1) {
                    ans[indarr[i] - 1] = "Gold Medal";
                } else if (rank == 2) {
                    ans[indarr[i] - 1] = "Silver Medal";
                } else if (rank == 3) {
                    ans[indarr[i] - 1] = "Bronze Medal";
                } else {
                    ans[indarr[i] - 1] = to_string(rank);
                }
                ++rank;
            }
        }

        return ans;
    }

};