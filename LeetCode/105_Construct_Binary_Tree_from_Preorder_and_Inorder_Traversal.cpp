/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildSubTree(vector<int> &preorder, vector<int> &inorder, int &pre_idx, int left, int right) {
        if(right <= left || pre_idx >= preorder.size()) return NULL;
        
        int pivot;
        for(int i = left; i < right; i++) {
            if(preorder[pre_idx] == inorder[i]) {
                pivot = i;
                break;
            }
        }
        
        TreeNode *root = new TreeNode(preorder[pre_idx++]);
        root -> left = build(preorder, inorder, pre_idx, left, pivot);
        root -> right = build(preorder, inorder, pre_idx, pivot + 1, right);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_idx = 0;
        return buildSubTree(preorder, inorder, pre_idx, 0, preorder.size());
    }
};