// name:检查整数及其两倍数是否存在
// 签到题
// 直接暴力  别排序了还麻烦 吃力不讨好
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(arr[i] == 2 * arr[j]) return true;
            }
        }
        return false;
    }
};