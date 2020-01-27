//name:�����ƻ�������Ѷ�
const int MAX = 300 + 50;
int dp[15][MAX];
//dp[i][j] ���� ǰ i �����ǰ j ����������Ҫ����С������
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
                    if(dp[i - 1][ret] != -1){ //ע�����ﲻҪ�� continue ��Ϊ��ÿ����һ��ret��Ҫ����һ��mx��ֱ��continue�͸��²���mx��
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