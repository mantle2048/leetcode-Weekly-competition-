class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> tmp(2, nums[0]);
        int n = nums.size();
        for(int i = 1; i < n; i++){
            tmp.insert(tmp.begin() + index[i], nums[i]);
        }
        tmp.pop_back();
        return tmp;
    }
};