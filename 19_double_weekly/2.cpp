// name:大小为 K 且平均值大于等于阈值的子数组数目
// 滑动窗口
// tips: 学会把除法变成乘法！
// 子数组一共拥有 n - k + 1 个
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0; int n = arr.size();
        threshold *= k;
        int ret = 0;
        for(int j = 0; j <  k; j++) ret += arr[j];          
        if(ret >= threshold) ++ans;
        for(int i = k; i  < n; i++){
            ret = ret - arr[i - k] + arr[i];
            if(ret >= threshold) ans++;
        }
        return ans;
    }
};