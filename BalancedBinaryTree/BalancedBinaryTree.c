/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
/**
 * if Tree is balanced tree, return height of the tree;
 * else return -1;
 */
    int getBalancedTreeHeight(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = getBalancedTreeHeight(root->left);
        if (leftHeight == -1) {
            return -1;
        }
        int rightHeight = getBalancedTreeHeight(root->right); 
        if (rightHeight == -1) {
            return -1;
        }
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return 1 + max(leftHeight, rightHeight);
    }
    
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int height = getBalancedTreeHeight(root);
        if (height == -1) {
            return false;
        }
        return true;
    }
};
