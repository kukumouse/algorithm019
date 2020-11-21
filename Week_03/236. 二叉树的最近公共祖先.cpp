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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if (!left) return right;
        else if (!right) return left;
        return root;
    }
};

/**
寻找公共祖先，二叉树的题还是需要对整个子树进行操作，先想好解题思路。
找出终止条件
找出左子树中的节点，
找出右子树节点。
返回公共父节点
**/