/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int moves = 0;
    int distributeCoins(TreeNode* root) {
        postOrder(root);
        return moves;
    }
    int postOrder(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int l = postOrder(root->left);
        int r = postOrder(root->right);

        moves += abs(l) + abs(r);

        return ( (root->val-1) + l + r);
    }
};