// 堆优化后的Dijstra
#define MAX 999999;
#define piii  pair<int, pair<int, int>>
#define m_p(x, y, z) make_pair(x, make_pair(y ,z))
const int MAXN = 150;
int dis[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
priority_queue<piii, vector<piii>, greater<>> Q;
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        memset(dis, -1, sizeof(dis));
        memset(visited, false, sizeof(visited));
        while(!Q.empty()) Q.pop();
        int m = grid.size(), n = grid[0].size();
        dis[0][0] = 0;
        Q.push(m_p(0, 0, 0)); 
        while(!Q.empty()){
            piii tmp = Q.top(); Q.pop();
            int x = tmp.second.first, y = tmp.second.second;
            visited[x][y] = true;
            for(int i = 1; i <= 4; i++){
                int nx = x + dx[i], ny = y + dy[i], cost = (grid[x][y] == i) ? 0 : 1;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(dis[nx][ny] == -1 || dis[nx][ny] > dis[x][y] + cost){
                    dis[nx][ny] = dis[x][y] + cost;
                    Q.push(m_p(dis[x][y], nx, ny));
                }
            }
        }
        return dis[m - 1][n -1];
    }
};