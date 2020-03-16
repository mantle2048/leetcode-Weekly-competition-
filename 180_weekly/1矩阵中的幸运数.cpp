// Ë¼Â·£º±©Á¦
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            int tmp1 = matrix[i][0];
            int column = 0;
            for(int j = 0; j < n; j++)
                if(matrix[i][j] < tmp1) tmp1 = matrix[i][j], column = j;
            int tmp2 = tmp1;
            for(int k = 0; k < m; k++)
                if(matrix[k][column] > tmp2) tmp2 = matrix[k][column];
            if(tmp1 == tmp2) ans.push_back(tmp1);
        }
        return ans;
    }
};