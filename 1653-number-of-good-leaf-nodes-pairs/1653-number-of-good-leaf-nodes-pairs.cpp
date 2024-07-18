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
    int ans=0;
    vector<int> recurs(TreeNode* root,int d){
        if(!root) return {};
        if(root->left==NULL && root->right==NULL) return{1};
        vector<int> l=recurs(root->left,d);
        vector<int> r=recurs(root->right,d);
        vector<int> neww;
        for(int a:l){
            for(int b:r){
                if(a+b<=d) ans++;
            }
        }
        for(int a:l){
            if(a+1<d) neww.push_back(a+1);
        }
        for(int b:r){
            if(b+1<d) neww.push_back(b+1);
        }
        return neww;
    }
    int countPairs(TreeNode* root, int distance) {
        recurs(root,distance);
        return ans; 
    }
};