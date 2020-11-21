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
private:
    long long res = LONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        if (!isValidBST(root->left))
            return false;
        if (res >= root->val)
            return false;
        res = root->val;
        return isValidBST(root->right);
    }
};

/**
验证一个二叉搜索树，从中序遍历出发，考虑中序遍历输出时后面的数永远比前面小。
解题思路其实很简单，对目前掌握的知识多巩固。解法其实很简单。
**/