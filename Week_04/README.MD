## 深度优先遍历
	
	递归的模板
	```
	map<int, int> visited;
	void dfs(Node* root) {
	  // terminator
	  if (!root) return ;
	  if (visited.count(root->val)) {
	    // already visited
	    return ;
	  }
	  visited[root->val] = 1;
	  // process current node here. 
	  // ...
	  for (int i = 0; i < root->children.size(); ++i) {
	    dfs(root->children[i]);
	  }
	  return ;
	}

## 广度优先遍历
	类似于水波纹扩散的算法，
	模板
	```
	void bfs(Node* root) {
	  map<int, int> visited;
	  if(!root) return ;
	  queue<Node*> queueNode;
	  queueNode.push(root);
	  while (!queueNode.empty()) {
	    Node* node = queueNode.top();
	    queueNode.pop();
	    if (visited.count(node->val)) continue;
	    visited[node->val] = 1;
	    for (int i = 0; i < node->children.size(); ++i) {
	        queueNode.push(node->children[i]);
	    }
	  }
	  return ;
	}

## 贪心算法
	每次都寻找局部最优解的算法，在不需要精确答案的时候经常被用于辅助算法。


## 二分查找
	在数组中寻找对象值，如果值不在左边则向右归并，如果值在右边则向左归并。
	在旋转数组中查找变异点。
	如果左边的数组为顺序则向右归并，反之向左直到找到变异点。
	```
	class Solution {
	public:
	    int search(vector<int>& nums, int target) {
	        int left = 0 , right = nums.size() - 1;
	        int mid = 0 ;
	        while (left < right){
	            mid = (left + right) / 2;
	            if (nums[left] < nums[mid]){
	                left = mid ;
	            }else if(nums[left] > nums[mid] ){
	                right = mid;
	            }
	            
	            if (mid + 1 < nums.size()-1 && nums[mid] > nums[mid+1] ){
	                return mid + 1; 
	            }
	            
	        }
	        return -1;
	    }
	};
	
	

	

