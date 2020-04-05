// 博弈问题，如果双方都选择最优策略就dp表征两者分值之差，一个试图最大化分差，一个试图最小化分差
static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
const int MAXN = 5e4 + 50;
int dp[MAXN][2]; //dp[][]代表当前选择到第i个石子 0 - Alice 1 - Bob 代表 Score(Alice) - Score(Bob)
class Solution {
public:
    vector<int> nums;
    int dfs(int x, int n, int turn){// 0 - Alice 1 - Bob
        if(x >= n) return 0;
        if(dp[x][turn] != MAXN) return dp[x][turn];
        if(turn == 0){
            int cur = nums[x];
            dp[x][turn] = cur + dfs(x + 1, n, 1); //最大化分差
            for(int i = x + 1; i < x + 3 && i < n; i++){
                cur += nums[i];
                dp[x][turn] = max(dp[x][turn], cur + dfs(i + 1, n, 1));
            }
        }
        else{
            int cur = nums[x];
            dp[x][turn] = dfs(x + 1, n, 0) - cur; //最小化分差
            for(int i = x + 1; i < x + 3 && i < n; i++){
                cur += nums[i];
                dp[x][turn] = min(dp[x][turn], dfs(i + 1, n, 0) - cur);
            }            
        }
        return dp[x][turn];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        nums =stoneValue;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++){
                dp[i][j] = MAXN;
            }
        }

        int ans =  dfs(0, n, 0);
        if(ans > 0) return "Alice";
        else if(ans == 0) return "Tie";
        else return "Bob";
    }
};