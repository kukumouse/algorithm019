class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0) return;
        int count = 0; //交换次数
        int length = nums.size();
        for (int i = 0 ; count < length ; i++)
        {
            int cur = i ; //从头开始翻转
            int per = nums[cur];
            do
            {
                int next = (cur + k) % length; //计算最后到达的位置
                int temp = nums[next];  //暂存替换中的值
                nums[next] = per;
                per = temp;
                cur = next; //下一次替换从 当前替换位出发
                count++;
            }while(i != cur);
        }
    }
};