const int MAXN = 150;
int dis[MAXN][MAXN];
bool visited[MAXN][MAXN]; //SPFA中已经出队列的节点可能还会再回来，用来记录当前节点是否在队列中
queue<pair<int, int> > Q;
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid[0].size(), m = grid.size();
        memset(dis, -1, sizeof(dis));
        memset(visited, false, sizeof(visited));
        while(!Q.empty()) Q.pop();
        dis[0][0] = 0; visited[0][0] = true;
        Q.push(make_pair(0, 0));
        while(!Q.empty()){
            pair<int, int> tmp = Q.front(); Q.pop();
            int x = tmp.first; int y = tmp.second;
            visited[x][y] = false;
            for(int i = 1; i <= 4; i++){
                int nx = x + dx[i], ny = y + dy[i], cost = dis[x][y] + (grid[x][y] == i ? 0 : 1);
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(dis[nx][ny] == -1 || dis[nx][ny] > cost){
                    dis[nx][ny] = cost;
                    if(!visited[nx][ny]) visited[nx][ny] = true, Q.push(make_pair(nx, ny));
                }
            }
        }
        return dis[m - 1][n - 1];
    }
};