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
    int goodNodes(TreeNode* root) {
      int num = 0;
      dfs(root,root->val, num);
      return num;
    }

    void dfs(TreeNode* root, int good, int &i){
      if( root == NULL)
        return ;
      good = max(root->val, good);
      dfs(root->left, good, i );
      dfs(root->right, good, i );
      if( root->val >= good)
        i++;
        
    } // if
};
