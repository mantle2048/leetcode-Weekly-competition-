#include<iostream>
#include<cstring>
using namespace std;
//name: 二指输入的的最小距离

//dp[i][a][b] 分别记录 当前输入到第i个字符, 当前左手处在a位置, 当前右手处在b位置
int dp[350][30][30];
class Solution {
public:
    inline int abs(int x){
        if(x < 0) return -x;
        return x;
    }
    int getX(int tmp){
        return tmp % 6;
    }
    int getY(int tmp){
        return tmp / 6;
    }
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        int n = word.length();
        dp[0][26][26] = 0;
        for(int i = 1; i <= n; i++){
            char letter = word[i - 1]; int cur = letter - 'A';
            for(int a = 0; a <= 26; a++){
                for(int b = 0; b <= 26; b++){
                    if(dp[i - 1][a][b] == -1) continue;
                    int cost = 0;
                    //A
                    if(a == 26) cost = 0;
                    else {cost = abs(getX(a) - getX(cur)) + abs(getY(a) - getY(cur));
                    }
                    if(dp[i][cur][b] == -1 || dp[i][cur][b] > dp[i - 1][a][b] + cost)
                        dp[i][cur][b] = dp[i - 1][a][b] + cost;
                    //B
                    if(b == 26) cost = 0;
                    else {cost = abs(getX(b) - getX(cur)) + abs(getY(b) - getY(cur));
                    }
                    if(dp[i][a][cur] == -1 || dp[i][a][cur] > dp[i - 1][a][b] + cost)
                        dp[i][a][cur] = dp[i - 1][a][b] + cost;
                }
            }
        }
        int ans = -1;
        for(int a = 0; a <= 26; a++){
            for(int b = 0; b <=26; b++){
                // cout << dp[n][a][b] <<endl;
                if(dp[n][a][b] == -1) continue;
                if(ans == -1 || ans > dp[n][a][b])
                    ans = dp[n][a][b];
            }
        }
        return ans;
    }
};
int main(){
    int tmp = 7;
    while(tmp < 10000){
        cout << (tmp <<= 1) << endl;
        // tmp <<= 1;
    }
}