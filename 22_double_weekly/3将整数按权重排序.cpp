const int MAXN = 1e6 + 50;
int dp[MAXN];

int solve(int x){ //¼ÇÒä»¯ËÑË÷
    if(dp[x] != -1) return dp[x];
    if(x & 1)
        dp[x] = solve(3 * x + 1) + 1;
    else  
        dp[x] = solve(x >> 1) + 1;
    return dp[x];
}
inline bool cmp(int a, int b){
    if(dp[a] == dp[b]) return a < b;
    else return dp[a] < dp[b];
}
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        memset(dp, -1, sizeof(dp));
        vector<int> buf;
        dp[1] = 0;
        for(int i = 2; i <= hi; i++) solve(i);
        for(int i = lo; i <= hi; i++) buf.push_back(i);
        sort(buf.begin(), buf.end(), cmp);
        return buf[k - 1];
    }
};