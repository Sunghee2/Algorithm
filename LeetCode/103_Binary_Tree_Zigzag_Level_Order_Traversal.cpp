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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int dir = 1;
        
        if(!root) return result;
        
        vector<int> element;
        queue<TreeNode*> tree_element;
        tree_element.push(root);
        
        while(!tree_element.empty()) {
            int size = tree_element.size();
            for(int i = 0; i < size; i++) {
                TreeNode *tmp = tree_element.front();
                tree_element.pop();
                
                element.push_back(tmp -> val);
                
                if(tmp -> left) tree_element.push(tmp -> left);
                if(tmp -> right) tree_element.push(tmp -> right);
            }
            
            if(dir == 0) {
                reverse(element.begin(), element.end());
            } 
            
            dir = dir == 1? 0 : 1;
            if(element.size() > 0) {
                result.push_back(element);
                element.clear();
            }
        }
        
        return result;
    }
};