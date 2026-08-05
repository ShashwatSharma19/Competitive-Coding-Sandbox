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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr)return result;

        queue<TreeNode*> q;
        q.push(root);
        bool Lefttoright = true;

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> currentLevel(levelSize);  

            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                
                int index = Lefttoright ? i : (levelSize - 1 - i);
                currentLevel[index] = curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            result.push_back(currentLevel);
            Lefttoright = !Lefttoright;  
        }

        return result;
    }
};