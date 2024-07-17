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
 #define null NULL

class Solution {
    TreeNode* helper(TreeNode* node,set<int>& nodeset,vector<TreeNode*>& res)
    {
        if(node==null)
            return node;

        node->left=helper(node->left,nodeset,res);
        node->right=helper(node->right,nodeset,res);

        if(nodeset.find(node->val)!=nodeset.end())
        {
            if(node->left!=null)
            {
                res.push_back(node->left);
            }
            if(node->right!=null)
            {
                res.push_back(node->right);
            }
            return null;
        }
        return node;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> nodeset;
        for(int x: to_delete)
        {
            nodeset.insert(x);
        }
        vector<TreeNode*> res;
        if (nodeset.find(root->val) == nodeset.end()) {
            res.push_back(root);
        }
        helper(root,nodeset,res);
        return res;
    }
};