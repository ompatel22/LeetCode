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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root)
            return root;
            
        removeLeafNodes(root->left,target);
        removeLeafNodes(root->right,target);

        if(isLeaf(root->left) && root->left->val==target)
        {
            root->left=NULL;
        }
        if(isLeaf(root->right) && root->right->val==target)
        {
            root->right=NULL;
        }
        if(isLeaf(root) && root->val==target)
        {
            root=NULL;
        }
        return root;
    }
    bool isLeaf(TreeNode* root)
    {
        if(!root)
            return false;
        if(!root->left && !root->right)
            return true;
        return false;
    }

};