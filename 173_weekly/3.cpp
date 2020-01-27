// name: 阈值距离内邻居最少的城市
// 最短路问题，可以有三种解法 SPFA 迪杰斯特拉 Floyd 另外两种明天再写
const int MAX = 150;
int dp[MAX][MAX];
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++)
            dp[i][i] = 0;
        for(auto cur : edges){
            int a = cur[0], b = cur[1], c = cur[2];
            dp[a][b] = c; dp[b][a] = c;
        }
        floyd(n);
        int minCity = -1; int ans;
        for(int i = 0; i < n; i++){
            int curCity = 0;
            for(int j = 0; j < n; j++){
                if(i == j || dp[i][j] > distanceThreshold) continue;
                curCity++;
            }
            if(minCity == -1 || minCity >= curCity){
                minCity = curCity; ans = i;
            }
        }
        return ans;
    }
    void floyd(int n){
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dp[i][k] == -1 || dp[k][j] == -1) continue;
                    if(dp[i][j] == -1 || dp[i][j] > dp[i][k] + dp[k][j])
                        dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
};