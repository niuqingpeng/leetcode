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
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val) {
                return true;
            }
            return false;
        }
        bool isHasPathSumLeft = false;
        bool isHasPathSumRight = false;
        if (root->left != NULL) {
            isHasPathSumLeft = hasPathSum(root->left, sum - root->val);
        }
        if (isHasPathSumLeft) {
            return true;
        }
        if (root->right != NULL) {
            isHasPathSumRight = hasPathSum(root->right, sum - root->val);
        }
        return isHasPathSumRight;
    }
};
