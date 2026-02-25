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
    int pathSum(TreeNode* root, int targetSum) {
      if(root == NULL)
        return 0;
      int num = dfs(root,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
      return num;  
    }
    
    int dfs(TreeNode* root, long long targetSum) {
      if( root == NULL)
        return 0;
    //   int left = dfs(root->left,targetSum - root->val);
    //   int right = dfs(root->right,targetSum - root->val);
      long long num = (targetSum - root->val == 0) ? 1 : 0;
      return num + dfs(root->left,targetSum - root->val) + dfs(root->right,targetSum - root->val);
      
    }
};
