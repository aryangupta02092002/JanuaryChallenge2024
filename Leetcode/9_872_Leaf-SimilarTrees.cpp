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
    void helper(TreeNode *root, vector<int> &tmp){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            tmp.push_back(root->val);
        }
        helper(root->left, tmp);
        helper(root->right, tmp);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tmp1, tmp2;
        helper(root1, tmp1);
        helper(root2, tmp2);
        return tmp1 == tmp2;
    }
};
