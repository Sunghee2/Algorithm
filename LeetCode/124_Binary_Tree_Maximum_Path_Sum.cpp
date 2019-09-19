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
    int max_value = INT_MIN;
    
    int postorder(TreeNode* root) {
        int left_sum = 0, right_sum = 0;
        int sum = root -> val;
        
        if(root -> left != NULL) left_sum = postorder(root -> left);
        if(root -> right != NULL) right_sum = postorder(root -> right);

        sum = max(max(left_sum, right_sum) + root -> val, root -> val);
        max_value = max(max_value, max(sum, left_sum + right_sum + root -> val));
        return sum;
    }
    
    int maxPathSum(TreeNode* root) {
        postorder(root);
        
        return max_value;
    }
};

/**
 * 이전에 풀었던 postorder 이용해서 풀음
 * sum값을 리턴하는 이유는
 * 왼쪽 오른쪽 노드 모두 합하면 그 이상의 path를 생성할 수 없기 때문.
 * **/