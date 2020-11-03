class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            if (n == 0) return;
            for (int i = m ,j = 0 ; i < nums1.size(); i++)
            {
                nums1[i] = nums2[j];
                ++j;
            }
            sort(nums1.begin(),nums1.end());
    }
};

//双指针方法
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

            if (m == 0) 
            {   
                nums1 = nums2;
                return;
            }
            if (n == 0 ) return;
            vector<int> temp;
            int i = 0, j = 0;
            int count = 0;
            while(count != m+n)
            {
                if (j==n || (i<m &&　nums1[i] < nums2[j]))
                {
                    temp.push_back(nums1[i]);
                    ++i;
                }else{
                    temp.push_back(nums2[j]);
                    ++j;
                }
                count++;
            }
            nums1 = temp;
    }
};