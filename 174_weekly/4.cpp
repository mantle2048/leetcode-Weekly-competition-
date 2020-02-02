//name:跳跃游戏 V
//dp题，dp[i]表示从I开始跳，最多可以访问多少下标
//递推式为 dp[i] = 从 [i - d, i + d](不包括 i)范围内最大值然后 + 1
//状态转移条件为 从 i 向左或者向右跳的同时 arr[j] < arr[i] 代表可以从 j->i 也就是当前状态dp[i]可以用dp[j]来更新
//tips:如何根据数组的值来排序下标：另开一个数组idx[]存放所有的下标，然后设置比较函数cmp return val[a] < val[b]按照数值的值进行对下标数组idx进行排序

#define max(a, b) ((a > b)? a : b)
const int MAXN = 1000 + 50;
int dp[MAXN];
vector<int> val;
bool cmp(const int& a, const int& b){ return val[a] < val[b]; }
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> idx(n, 0); val = arr;
        for(int i = 0; i < n; i++)
            idx[i] = i;
        sort(idx.begin(), idx.end(), cmp);
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for(int _i = 0; _i < n; _i++){
            int i = idx[_i];
            dp[i] = 1;
            for(int j = i - 1; j >= 0 && j >= i - d; j--){
                if(arr[j] >= arr[i]) break;
                dp[i] = max(dp[i], dp[j] + 1);
            }
            for(int j = i + 1; j < n && j <= i + d; j++){
                if(arr[j] >= arr[i]) break;
                dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};