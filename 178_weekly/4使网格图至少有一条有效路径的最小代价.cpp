// name:ʹ����ͼ������һ����Ч·������С����
// ֻҪ������ͼ������bfs or dfs ���� �Ͻ�˹���� SPFA������DP
// ˼· 

//  BFS: �ڶ����б�ȨΪ1, dis = x -> ��dis�ڽӵĵ�ľ���һ��Ϊ = x + 1��Ȼ��ȫ�����
//  x x x x x x  (x + 1) (x + 1) (x + 1) (x + 1) (x + 1)
//  0 - 1 BFS�� �ڶ����б�ȨΪ 1 || 0, dis = x -> ��dis�ڽӵĵ�ľ������Ϊ x Ҳ����Ϊ x + 1
// x | x.....x (x + 1) (x + 1) (x + 1)... ����һ��˫����У� �������Ϊx �ŵ�����
const int MAXN = 150;
int dis[MAXN][MAXN];
bool visited[MAXN][MAXN]; //BFS�����Խڵ�ֻ�����һ�Σ����ֻҪ���ʹ������˾Ͳ����ٷ�����
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