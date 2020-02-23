// name: 形成三的最大倍数
// 思路：妙啊，太妙了，这简直是艺术。 
// 计算出初始数组的sum
// 如果sum % 3 == 2 则需要消除一个膜3为2的值(2,5,8)，如果都没有则要删除两个膜3为1的值(1,4,7)
// 如果sum % 3 == 1,则需要消除一个膜3为1的值(1,4,7)，如果都没有则要删除两个膜3为2的值(2,5,8)
// tips: 对于这种用0-9的数字拼字符串的题，可以用cnt[10]数组统计每个数字出现的次数
class Solution {
public:
    int cnt[10], sum;
    string ans = "";
    int del(int m){
        for(int i = m; i < 10; i += 3) if(cnt[i]){cnt[i]--; return 1;}
        return 0;
    }
    string largestMultipleOfThree(vector<int>& digits) {
        for(auto i : digits) cnt[i]++, sum += i;
        if(cnt[0] == digits.size()) return "0"; //排除全为0
        if(sum % 3 == 1) if(!del(1)) del(2),del(2);
        if(sum % 3 == 2) if(!del(2)) del(1),del(1);
        int cnt_0 = cnt[0]; //记录下删除完后的字符中是否只剩下0
        for(int i = 9; i >= 0; i--){
            while(cnt[i]--) ans += i + '0';
        }
        if(ans.length() == cnt_0) return "0"; //排除类似[1,0,0]这种类型删除完最后只剩下0
        return ans;
    }
};