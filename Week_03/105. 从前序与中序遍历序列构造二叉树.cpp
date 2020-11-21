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
    unordered_map<int,int> map;
public:
    TreeNode* buildTree(vector<int>& preorder,int pleft,int pright,int ileft,int iright){
        if (pleft>pright)
            return NULL;
        
        int i_root_index = map[preorder[pleft]];
        int left_size = i_root_index - ileft;
        TreeNode* newNode = new TreeNode(preorder[pleft]);
        newNode->left = buildTree(preorder,pleft+1,pleft + left_size ,ileft,i_root_index - 1);
        newNode->right = buildTree(preorder,pleft+left_size +1,pright,i_root_index + 1,iright);
        return newNode;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for (int i = 0;i< inorder.size();i++){
            map[inorder[i]] = i;
        }
        int len = inorder.size();
        return buildTree(preorder,0,len - 1,0,len -1);
    }
};
/**
找出最近子问题，
前序遍历的数组的第一个值是根元素，从而可以得知中序遍历的根元素下标，中序遍历数组中，在根元素左边的就是左树，右边的就是右树，
从而可以找到子文字，每次找一个根节点然后重建他的左右子树。

**/