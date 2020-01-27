//name:工作计划的最低难度
const int MAX = 300 + 50;
int dp[15][MAX];
//dp[i][j] 代表 前 i 天完成前 j 项任务所需要的最小工作量
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(int i = 1; i <= d ; i++){
            for(int cur = 1; cur <= n; cur++){
                int mx = jobDifficulty[cur - 1];
                for(int ret = cur - 1; ret >= 0; ret--){
                    if(dp[i - 1][ret] != -1){ //注意这里不要用 continue 因为你每进行一次ret都要更新一下mx，直接continue就更新不到mx了
                        if(dp[i][cur] == -1 || dp[i][cur] > dp[i - 1][ret] + mx)
                            dp[i][cur] = dp[i - 1][ret] + mx;
                    }
                    if(ret > 0) mx = max(mx, jobDifficulty[ret - 1]);
                }
            }
        }
        return dp[d][n];
    }
};