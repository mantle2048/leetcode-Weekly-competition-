// name:使网格图至少有一条有效路径的最小代价
// 只要看到地图优先想bfs or dfs 再想 迪杰斯特拉 SPFA　再想DP
// 思路 

//  BFS: 在队列中边权为1, dis = x -> 与dis邻接的点的距离一定为 = x + 1，然后全部入队
//  x x x x x x  (x + 1) (x + 1) (x + 1) (x + 1) (x + 1)
//  0 - 1 BFS： 在队列中边权为 1 || 0, dis = x -> 与dis邻接的点的距离可能为 x 也可能为 x + 1
// x | x.....x (x + 1) (x + 1) (x + 1)... 利用一个双向队列， 如果距离为x 放到队首
const int MAXN = 150;
int dis[MAXN][MAXN];
bool visited[MAXN][MAXN]; //BFS中所以节点只会访问一次，因此只要访问过出队了就不用再访问了
deque<pair<int, int> > Q;
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid[0].size(), m = grid.size();
        memset(dis, -1, sizeof(dis));
        memset(visited, false, sizeof(visited));
        while(!Q.empty()) Q.pop_back();
        dis[0][0] = 0;
        Q.push_back(make_pair(0, 0));
        while(!Q.empty()){
            pair<int, int> tmp = Q.front(); Q.pop_front();
            int x = tmp.first; int y = tmp.second;
            if(visited[x][y]) continue;
            visited[x][y] = true;
            for(int i = 1; i <= 4; i++){
                int nx = x + dx[i]; int ny = y + dy[i]; int cost = dis[x][y] + (grid[x][y] == i ? 0 : 1);
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(dis[nx][ny] == -1 || dis[nx][ny] > cost){
                    dis[nx][ny] = cost;
                    if(grid[x][y] == i) Q.push_front(make_pair(nx, ny));
                    else Q.push_back(make_pair(nx, ny));
                }
            }
        }
        return dis[m - 1][n - 1];
    }
};