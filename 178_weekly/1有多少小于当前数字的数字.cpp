//name:有多少小于当前数字的数字
// 思路：数据很小直接二重循环暴力
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && nums[j] < nums[i])
                    ans[i]++;
            }
        }
        return ans;
    }
};