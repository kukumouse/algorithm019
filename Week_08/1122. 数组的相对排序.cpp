class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> map;
        vector<int> ans;
        int index = arr2.size();
        sort(arr1.begin(),arr1.end());
        for (int i = 0;i< arr2.size();i++){
            map[arr2[i]] = i;
        }
        for (int n :arr1){
            int p ;
            if (map.count(n)){
                p = map[n];
            }else{
                p = index++;
            }
            pq.push({p,n});
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};