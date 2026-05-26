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
              TreeNode* Trim(TreeNode* root,int low,int high){
                      if(!root) return NULL;
                              if(root->val<low){
                                         return Trim(root->right,low,high);
                                                  }
                                                          if(root->val>high){
                                                                     return Trim(root->left,low,high);
                                                                              }
                                                                                      root->left=Trim(root->left,low,high);
                                                                                              root->right=Trim(root->right,low,high);
                                                                                                      return root;
                                                                                                          }
                                                                                                              TreeNode* trimBST(TreeNode* root, int low, int high) {
                                                                                                                      return Trim(root,low,high);
                                                                                                                          }
                                                                                                                          };