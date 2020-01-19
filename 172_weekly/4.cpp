#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
//name:��Ȼ�԰������ˮ��ͷ��Ŀ
//˼·��һάdp,dp[n]�����0->n����Ҫ�����ٵ�ˮ��ͷ��
#define max(a, b)  a > b ? a : b
#define min(a, b)  a < b ? a : b
const int MAX = 1e4 + 50;
int dp[MAX];
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i <= n; i++){
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            for(int cur = left; cur <= right; cur++){
                if(dp[left] == -1) continue;
                if(dp[cur] == -1 || dp[cur] > dp[left] + 1)
                    dp[cur] = dp[left] + 1;
            }
        }
        return dp[n];
    }
};
int main(){
    Solution tmp;
    vector<int> ranges = {1,2,1,0,2,1,0,1};
    int t= tmp.minTaps(7,ranges);
    cout << t << endl;
    return 0;
}