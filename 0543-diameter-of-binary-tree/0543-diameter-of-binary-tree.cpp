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
 int diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        dfs(root);
        return diameter;
    }
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftHeight = dfs(root->right);
        int rightHeight = dfs(root-> left);

        diameter = max(diameter, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }
};