//name:6 和 9 组成的最大数字
// 思路：从前到后读取数字, 读取到6就直接变为9返回
// tips: 从前到后遍历数字 num 首先确定当前位的权重 i(即确定数字num的位数 to_string(num))，当前位数 cur = num / i 每次 cur = cur % i， i /= 10
//       从后向前遍历数字 num 当前位数 cur = num % 10, num /= 10
class Solution {
public:
    int maximum69Number (int num) {
        for(int i = 1000, cur = num; i >0; i /= 10){
            int now = cur / i; cur = cur % i;
            if(now == 6) return num + (3 * i);
        }
        return num;
    }
};