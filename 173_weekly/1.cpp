//name: 删除回文子序列
// 回文子序列，注意不是子串，不一定要物理上连续 中间可以有间隔， 卡了我好久。。。这道题
class Solution {
public:
    int removePalindromeSub(string s) {
        if(s == "") return 0;
        int n = s.length();
        bool flag = true;
        int i = 0, j = n - 1;
        for(int i = 0; i < n; i++)
            if(s[i] != s[n - 1 - i]) flag = false; // 不用使用双指针，直接一个轴点 i 从头遍历
        return flag ? 1 : 2;
    }
};