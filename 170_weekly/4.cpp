#include<iostream>
#include<string>
#include<cmath>
using namespace std;

#define MAX 550
int dp[MAX][MAX];
class Solution {
public:
    int dfs(int l, int r, const string& s){
        if(r - l <= 0) return 0;
        if(::dp[l][r] != -1) return ::dp[l][r];//这一条不加就超时
        if(s[l] == s[r])
            ::dp[l][r] = dfs(l + 1, r - 1, s);
        else
            ::dp[l][r] = min(dfs(l + 1, r, s), dfs(l, r - 1, s)) + 1;
        cout << "dp[" << l << "][" << r << "] = " << ::dp[l][r] << endl;
        return ::dp[l][r];
    }
    int dp(int l, int r, const string& s, int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int tmp1 = MAX, tmp2 = MAX, tmp3 = MAX;
                if(i <= j) ::dp[i][j] = 0;
                if(i - 1 >= 0)
                    tmp1 = ::dp[i-1][j];
                if(j + 1 <= n-1)
                    tmp2 = ::dp[i][j+1];
            }
        }
    }
    int minInsertions(string s) {
        int n = s.length();
        for(int i = 0; i < n + 10; i++){
            for(int j = 0; j < n + 10; j++){
                ::dp[i][j] = -1;
            }
        }
        for(int i = 0; i < n; i++)
            ::dp[i][i] = 0;
        return dfs(0, n - 1, s);//记忆化搜索        
    }
};

int main(){
    Solution ans;
    int tmp = ans.minInsertions("leetcode");
}