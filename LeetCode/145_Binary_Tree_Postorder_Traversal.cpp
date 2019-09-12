// *
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };

class Solution {
public:
    void postorder(vector<int> &result, TreeNode* root) {
        if(root -> left != NULL) postorder(result, root -> left);
        if(root -> right != NULL) postorder(result, root -> right);
        result.push_back(root -> val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
    
        if(root != NULL) postorder(result, root);
        
        return result;
    }
};