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
    int maxLevelSum(TreeNode* root) {  
        vector<int> ans;
        dfs(root,0,ans);
        int mx = -INT_MAX;
        int level = 0;
        for(int i = 0 ; i < ans.size() ; i++){
          if( mx < ans[i] ){
            mx = ans[i];
            level = i+1;
          } // if
        } // for
        return level;
    //   int ans = -INT_MAX, level = 0, j = 0;
    //   queue<TreeNode*> q;
    //   if(root == NULL)
    //     return level;
    //   q.push(root);
    //   while(!q.empty() ){
    //     int k = q.size(); // 這是每一個level的值
    //     int sum = 0;
    //     j++;
    //     for( int i = 0 ; i < k ; i++ ){
    //       TreeNode* temp = q.front();
    //       int qf = temp->val;
    //       sum += qf;
    //       q.pop();
    //       if(temp->left != NULL)
    //         q.push(temp->left);
    //       if(temp->right != NULL)
    //         q.push(temp->right);            
    //     } // for
    //     if( sum > ans ){
    //       ans = sum;
    //       level = j;
    //     } //if
    //   } // while
    //   return level;
    }

    void dfs(TreeNode* root, int depth, vector<int> &ans){
      if(root == NULL)
        return;
      if(ans.size() < depth+1 )
        ans.push_back(0); 
      ans[depth] += root->val;
      dfs(root->left,depth+1,ans);
      dfs(root->right,depth+1,ans);
      
    } // dfs
};
