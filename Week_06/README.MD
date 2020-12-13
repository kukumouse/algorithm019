## 动态规划
	
	寻找重复子问题，
	本质上和分治和回溯和递归一样。
	分治模板
	```
	int divide_conquer(Problem *problem, int params) {
  		// recursion terminator
  		if (problem == nullptr) {
    		process_result
    		return return_result;
  		} 

	  // process current problem
	  subproblems = split_problem(problem, data)
	  subresult1 = divide_conquer(subproblem[0], p1)
	  subresult2 = divide_conquer(subproblem[1], p1)
	  subresult3 = divide_conquer(subproblem[2], p1)
	  ...

	  // merge
	  result = process_result(subresult1, subresult2, subresult3)
	  // revert the current level status
	 
	  return 0;
	}
	

	
	

	

