const int MAXN = 500 + 50;
int dp[MAXN * 3][MAXN * 3];

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n + n; i++)
            dp[i][i + 2] = slices[(i + 1) % n];
        
        for (int len = 3; len < n; len++){
            if (len % 3 != 2) continue;
            for (int left = 0; left < n + n; left++){
                int right = left + len;
                if (right >= n + n) continue;
                for (int mid = left + 1; mid < right; mid++){
                    if ((mid - left - 1) % 3 != 0) continue;
                    if ((right - mid - 1) % 3 != 0) continue;
                    int cur = slices[mid % n];
                    if (mid != left + 1){
                        if (dp[left + 1][mid - 1] == -1) continue;
                        cur += dp[left + 1][mid - 1];
                    }
                    if (mid + 1 != right){
                        if (dp[mid + 1][right - 1] == -1) continue;
                        cur += dp[mid + 1][right - 1];
                    }
                    dp[left][right] = max(dp[left][right], cur);
                }
                for (int mid = left; mid < right; mid++){
                    if (dp[left][mid] == -1) continue;
                    if (dp[mid + 1][right] == -1) continue;
                    dp[left][right] = max(dp[left][right], dp[left][mid] + dp[mid + 1][right]);
                }
                // if (dp[left][right] != -1) printf("%d %d = %d\n", left, right, dp[left][right]);
            }

        }
        
        int ans = -1;
        for (int i = 0; i < n; i++) if (dp[i][i + n - 1] != -1) ans = max(ans, dp[i][i + n - 1]);
        
        return ans;
    }
};