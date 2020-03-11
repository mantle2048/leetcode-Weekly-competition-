// 赛场上的思路：算出当前开着的灯的编号的和sum是否等于当前时刻i(1,2,3,4.....i + 1)的等差数列和
// 最简思路：记录开灯的max位置，记录开灯数，当两者相等就记录当前时刻，实在是太妙了！！
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size();
        ll sum = 0, ans = 0;
        for(int i = 0; i < n; i++){
            int cur = light[i];
            sum += cur;
            if(sum * 2 == (ll)(1 + (i + 1)) * (i + 1)) ans++;
        }
        return ans;
    }
};