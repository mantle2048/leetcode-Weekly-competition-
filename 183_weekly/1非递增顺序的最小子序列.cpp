class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0;
        priority_queue<int,vector<int>> Q;
        for(auto num : nums){
            sum += num;
            Q.push(num);
        }
        vector<int> ans;
        int now = 0;
        while(!Q.empty()){
            int cur = Q.top(); Q.pop(); sum -= cur;
            ans.push_back(cur); now += cur;
            if(now > sum) break;
        }
        return ans;
    }
};