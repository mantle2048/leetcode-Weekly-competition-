// name: 统计有序矩阵中的负数 数据很小直接暴力
// 一行代码的话 for(auto row : grid) for (auto v : row) if(v < 0) ++ans;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] < 0){
                    ans += n - j; //可以节省一点点时间遇到第一个复数就直接加上剩余的数字的个数
                    break;
                }
            }
        }
        return ans;
    }
};