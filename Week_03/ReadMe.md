## 泛型递归
	爬楼梯，斐波那契数列，汉诺塔，都是典型的递归。
	从简单题目入手找到最近重复子问题。
	递归程序的编写在于寻找最近重复子问题。
	递归的模板
	```
	class Solution {
	public:
	    int fib (int n)
	    {
	    	//递归终止条件
	        if (n  == 0) return 1;
	        //本层操作
			n+=fib(n-1);
	        //下探一层
	        return n;
	        //复原
	    }
	    
	};

## 树递归
	树形结构非常适合递归算法，
	树的中序，前序，后序遍历都可以使用递归简单的完成。
	```
	class Solution {
	public:
	    void inorder (TreeNode* root,vector<int> & res)
	    {
	        if (!root)
	            return ;
	        
	        inorder(root->left,res);
	        res.push_back(root->val);
	        inorder(root->right,res);
	    }
	    vector<int> inorderTraversal(TreeNode* root) {
	        vector<int> res;
	        inorder(root,res);
	        return res;
	    }
	};

## 分治算法
	把一个大问题拆分成N个子问题，最终再合并
	分治算法通常以数学归纳法来验证。而它的计算成本则多数以解递归关系式来判定。
	

## 回溯算法
	组合，N皇后，
	通过不停的尝试寻找答案来求解，
	如果本层中没有适合的答案，
	回到上一层继续寻找答案。
	回溯算法中在本层的最后需要吧这层修改的子值在最后复原。
	
## 递归算法
	递归算法的求解在于寻找最近重复性。
	递归的模板
	1.寻找出口的条件
	2.本层中的逻辑处理  问题如果适合分治算法需要优化剪枝 回溯算法的话需要在最后回溯本层的子值
	3.下探到下一层
	4.回溯本层
	

