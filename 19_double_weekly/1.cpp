// name:将数字变成 0 的操作次数
// 签到题
// tips: 判断奇数偶数，别再傻傻的%2了 直接 num & 1取最后一位, 巧妙利用位运算
class Solution {
public:
    int numberOfSteps (int num) {
        int ans = 0;
        while(num != 0){
            ++ans;
            if(num & 1) num -= 1;
            else num = num >> 1;
        }
        return ans;
    }
};