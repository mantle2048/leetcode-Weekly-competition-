// a e i o u 每种出现的次数为奇数或偶数，五种字母一共有32种状态，因此联想到状态压缩
// 遍历字符串
// 每走一个位置就记录下当前字符串位置p的元音字母出现的奇偶(比如1,0,1,0,1)
// 如果后来又在位置q出现了相同的奇偶状态(1,0,1,0,1)，则在q - p 的这一段里元音字母一定都出现了偶数次
// 0 ------ p -------- q
// 有点类似记录两个前缀和然后相减，求一段

// tips：当要求有限个字母或数字的有限个状态时，要记得联想到状态压缩技巧
// tips: 字符串灵活使用前缀和
class Solution {
public:
    int c2i(char c){
        if(c == 'a') return 0;
        if(c == 'e') return 1;
        if(c == 'i') return 2;
        if(c == 'o') return 3;
        if(c == 'u') return 4;
        return -1;
    }
    int findTheLongestSubstring(string s) {
        int State[32]; // State记录状态第一次出现的位置 cnt记录每种元音字母出现的次数
        int n = s.length(), ans = 0;
        int cnt[5] = {0};
        for(int i = 0; i < 32; i++) State[i] = n;
        State[0] = -1; // 初始化很关键，所有字母都出现偶数次(0,0,0,0,0)的状态初始为-1
        for(int i = 0; i < n; i++){
            if(c2i(s[i]) != -1) cnt[c2i(s[i])]++;
            int cur = 0;
            for(int k = 0; k < 5; k++){
                cur += (1<<k) * (cnt[k] & 1);
            }
            if(State[cur] == n) State[cur] = i;
            else
                ans = max(ans, i - State[cur]);
        }
        return ans;
    }
};