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
    vector<int> rightSideView(TreeNode* root) {
      if(root == NULL)
        return {};    
      vector<int> ans;
      dfs(root,ans,0);
      return ans;
    //   if(root == NULL)
    //     return {};
    //   queue<TreeNode*> q;
    //   q.push(root);
    //   vector<int> a;
    //   while( ! q.empty() ){
    //     int n = q.size();
    //     for( int i = 0 ; i < n ; i++){
    //       TreeNode* temp = q.front();
    //       q.pop(); 
    //       if( i == n -1 )
    //         a.push_back(temp->val); 
    //       if( temp->left != NULL)
    //         q.push(temp->left);
    //       if( temp->right != NULL)
    //         q.push(temp->right);

    //     } //for
    //   } // while
    //   return a;
    }

    void dfs(TreeNode* root, vector<int> &ans, int depth){
      if( root == NULL)
        return;
      if(depth == ans.size())
        ans.push_back(root->val);
      dfs(root->right,ans,depth+1);
      dfs(root->left,ans,depth+1);
    } // dfs;
};
