// name: 方阵中战斗力最弱的 K 行
// 统计每一行的战斗力，按每一行战斗力给下标排序
// 用map也行就是比较麻烦
const int MAXN = 150;
vector<int> battle(MAXN), idx(MAXN);
bool cmp(const int& a, const int& b){
    if(battle[a] != battle[b]) return battle[a] < battle[b];
    return a < b;
}
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        for(int i = 0; i < battle.size(); i++) battle[i] = 0;
        for(int i = 0; i < idx.size(); i++) idx[i] = 0;
        for(int i = 0; i < n; i++){
            idx[i] = i;
            for(auto j : mat[i]) battle[i] += j;
        }
        sort(idx.begin(), idx.begin() + n, cmp);
        vector<int> ans;
        for(int i = 0; i < k; i++) ans.push_back(idx[i]);
        return ans;
    }
};