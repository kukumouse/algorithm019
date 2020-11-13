## Hash表
	根据传入的值进行Hash函数计算Index值
	Hash函数计算出的值相同时会出现Hash碰撞的问题，通常使用链表解决。
	查询是O(1) 删除O(1) 添加O(1) 出现碰撞时候退化成O(n)

## Map
	从Hash表进化，以键值对的方式存储Key不重复。
 	查询变成O(1)

## SET
	通常作为抽象接口存在，有多重实现。
	TreeSet 使用红黑树实现 查询是O(logn) 删除O(logn) 添加O(logn)

## 树二叉树 二叉搜索树
	树形结构更加接近真实世界。
	查询删除增加为 O(2logN)
	
## 堆 二叉堆
	大顶堆小顶堆，根据实际的业务实现。
	find-max:O(1)
	delete-max O(logN)
	insert O(logN) or O(1)
	索引为i的左节点的索引是(2*i+1)
	索引为i的右节点的索引是(2*i+2)
	索引为i的父节点的索引是floor((i-1)/2)
	

