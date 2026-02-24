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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) { // 這題不會寫
      vector<int> r1,r2;
      getLeave(root1,r1);
      getLeave(root2,r2);
      return r1 == r2;
    } // 

    void getLeave(TreeNode* root, vector<int>& vec){ // 解法式把樹葉存vector
      if( root == NULL )
        return;
      getLeave( root->left, vec);
      getLeave( root->right, vec);
      if( root->left == NULL &&  root->right == NULL ){  // leave
        vec.push_back(root->val);
      } // if
    } // getLeave
};
