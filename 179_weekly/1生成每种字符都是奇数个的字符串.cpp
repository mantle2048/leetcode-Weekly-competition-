// 思路：奇数就返回全a 偶数就返回n - 1个 a 和一个 b
class Solution {
public:
    string generateTheString(int n) {
        string ans = "";
        if(n & 1){ //奇数
            for(int i = 0; i < n; i++) ans += 'a';
            return ans;
        }
        else{//偶数
            for(int i = 0; i < n - 1; i++) ans += 'a';
            ans +='b';
            return ans;
        }
    }
};